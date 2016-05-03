
#include "vst/CyFlowVisitor.h"

#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>

using namespace std;

// --------------------------------------------------------------------------
int CyFlowVisitor::visit(FunctionDefinition* decl)
{
    CyFlowDotGraph *graph = new CyFlowDotGraph(decl->toString());
    this->_graph = graph;
    this->_graphs.push_back(this->_graph);

    /* 起点を作成 */
    this->_path = this->_graph->createPath(NULL);

    /* 関数本体にaccept */
    decl->getStatement()->accept(this);

    /* 終点を作成 */
    this->_path->close(NULL);

    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(TranslationUnit* stmt)
{
    this->_src = stmt->getSource();
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(NullStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(CompoundStatement* stmt)
{
    return stmt->getStatement()->accept(this);
}

int CyFlowVisitor::visit(ExpressionStatement* stmt)
{
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);
    this->_path->push(node);
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(IfStatement* stmt)
{
    int ope1, ope2;
    CyFlowDotEdge *edge;
    CyFlowDotNode *node, *confluence;
    CyFlowPath    *pathTrue, *pathElse;
    
    /* IFノード追加 */
    node = CyFlowDotNode::factory(stmt);
    edge = this->_path->push(node);

    /* IFノードのラベルは右上に表示 */
    edge->setHeadLabel(stmt->toString());
    edge->setProperty("labelfloat", "true");
    edge->setProperty("labeldistance", "3.0");
    edge->setProperty("labelangle", "-45");

    /* true */
    ope1 = stmt->getTrue()->accept(this);

    /* else */
    pathElse = this->_graph->createPath(node);
    pathTrue = this->pathSwitch(pathElse);
    this->_path->getLastEdge()->setHeadLabel("False");
    this->_path->getLastEdge()->setProperty("labelfloat", "true");
    this->_path->getLastEdge()->setProperty("labelangle", "90");
    this->_path->getLastEdge()->setProperty("labeldistance", "1");
    ope2 = stmt->getElse()->accept(this);

    if ( ope1 == CyVisitor::VISIT_CONTINUE
            && ope2 == CyVisitor::VISIT_CONTINUE )
    {
        /* 合流地点を作成 */
        confluence = CyFlowDotNode::factoryConfluenceNode();
        pathTrue->push(confluence);

        /* elseパスは終了 */
        pathElse->close(confluence);

        /* 続きはTrueの流れで */
        this->pathSwitch(pathTrue);
    }
    else
    {
        if ( ope1 == CyVisitor::VISIT_CONTINUE )
        {
            /* 合流地点から継続 */
            this->pathSwitch(pathTrue);
            return ope2;
        }
        else if ( ope2 == CyVisitor::VISIT_CONTINUE )
        {
            /* 合流地点から継続 */
            this->pathSwitch(pathElse);
            return ope1;
        }
    }

    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(WhileStatement* stmt)
{
    CyFlowDotNode *loopBegin, *loopEnd;
    CyFlowDotEdge* edge;
    int ope;

    /* ループ開始と終了ノードを作成 */
    loopBegin = CyFlowDotNode::factory(stmt);
    loopEnd   = CyFlowDotNode::factoryLoopEnd();
    CyFlowIteration it(loopBegin, loopEnd);
    this->_its.push_back(it);

    /* 繰り返しノードを追加 */
    edge = this->_path->push(loopBegin);
    edge->setHeadLabel(stmt->toString());
    edge->setProperty("labelfloat", "true");
    edge->setProperty("labelangle", "-90");

    /* for本体 */
    ope = stmt->getStatement()->accept(this);

    /* loop終了 */
    this->_its.pop_back();

    /* for終点をつなげる */
    this->_path->push(loopEnd);
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ForStatement* stmt)
{
    int ope;
    CyFlowDotNode *loopBegin, *loopEnd;
    CyFlowDotEdge* edge;

    /* ループ開始と終了ノードを作成 */
    loopBegin = CyFlowDotNode::factory(stmt);
    loopEnd   = CyFlowDotNode::factoryLoopEnd();
    CyFlowIteration it(loopBegin, loopEnd);
    this->_its.push_back(it);

    /* 繰り返しノードを追加 */
    edge = this->_path->push(loopBegin);
    edge->setHeadLabel(stmt->toString());
    edge->setProperty("labelfloat", "true");
    edge->setProperty("labelangle", "-90");

    /* for本体 */
    ope = stmt->getStatement()->accept(this);

    /* loop終了 */
    this->_its.pop_back();

    /* for終点をつなげる */
    this->_path->push(loopEnd);
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(DoStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(GotoStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(LabeledStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(BreakStatement* stmt)
{
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);
    this->_path->push(node);

    /* 直近のIterate(loop, switch)の終点につなげる */
    CyFlowDotEdge* edge;
    edge = this->_path->push(this->_its.back().end());
    edge->setProperty("weight", "1.0");
    edge->setProperty("style", "dotted");

    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ContinueStatement* stmt)
{
    CyFlowDotEdge* edge;
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);
    edge = this->_path->push(node);

    /* 直近のIterate(loop, switch)の起点につなげる */
    edge = this->_path->push(
                node->getNodeName(), 
                this->_its.back().begin()->getNodeName());
    edge->setProperty("weight", "1.0");
    edge->setProperty("style", "dotted");

    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ReturnStatement* stmt)
{
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);
    this->_path->push(node);
    return CyVisitor::VISIT_RETURN;
}

int CyFlowVisitor::visit(SwtStatement* stmt)
{
    CyFlowPath *path;
    Statement  *sibling;

    path = this->_path;

    /* switchノード作成 */
    CyFlowDotNode *node       = CyFlowDotNode::factory(stmt);
    CyFlowDotNode *confluence = CyFlowDotNode::factoryConfluenceNode();
    this->_path->push(node);

    /* Switch開始 */
    CyFlowIteration it(node, confluence);
    this->_its.push_back(it);

    stmt->getStatement()->accept(this);

    /* Switch終了 */
    this->_its.pop_back();
    this->pathSwitch(path);
    this->_path->push(confluence);
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(CaseStatement* stmt)
{
    int ope;
    CyFlowPath    *path, *pathold;;
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);

    /* パスの追加 */
    path = this->_graph->createPath(this->_its.back().begin());

    /* 切り替えて内部処理をトレース */
    pathold = this->pathSwitch(path);
    this->_path->getLastEdge()->setHeadLabel(stmt->toString());
    this->_path->getLastEdge()->setProperty("labelfloat", "true");
    this->_path->getLastEdge()->setProperty("labelangle", "-90");
    this->_path->getLastEdge()->setProperty("labeldistance", "2");

    ope = stmt->getStatement()->accept(this);
    if ( ope == CyVisitor::VISIT_CONTINUE )
    {
        if ( stmt->hasNextSibling() )
        {
            ope = stmt->getNextSibling()->accept(this);
        }
    }

    return CyVisitor::VISIT_CONTINUE;;
}

int CyFlowVisitor::visit(DefaultStatement* stmt)
{
    int ope;
    CyFlowPath    *path, *pathold;;

    /* パスの追加 */
    path = this->_graph->createPath(this->_its.back().begin());

    /* 切り替えて内部処理をトレース */
    pathold = this->pathSwitch(path);
    this->_path->getLastEdge()->setHeadLabel(stmt->toString());
    this->_path->getLastEdge()->setProperty("labelfloat", "true");
    this->_path->getLastEdge()->setProperty("labelangle", "90");
    this->_path->getLastEdge()->setProperty("labeldistance", "1");

    ope = stmt->getStatement()->accept(this);

    /* 元に戻す */
    this->pathSwitch(pathold);
    return ope;
}


void CyFlowVisitor::save(const char* fpath)
{
    std::vector<CyFlowDotGraph*>::iterator it;
    for ( it = this->_graphs.begin(); it != this->_graphs.end(); it++ )
    {
        CyFlowDotGraph* graph = *it;
        graph->saveDotFile(fpath);
    }
}

