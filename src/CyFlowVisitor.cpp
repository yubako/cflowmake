
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

    return CyVisitor::VISIT_CONTINUE;
}

void CyFlowVisitor::leave(FunctionDefinition* decl)
{
    /* 終点を作成 */
    this->_path->close(NULL);
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
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(DefaultStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
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
    edge->setHeadLabel(stmt->toString());

    /* true */
    ope1 = stmt->getTrue()->accept(this);

    /* else */
    pathElse = this->_graph->createPath(node);
    pathTrue = this->pathSwitch(pathElse);
    this->_path->getLastEdge()->setProperty("label", "False");
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
        }
        else
        {
            /* 合流地点から継続 */
            this->pathSwitch(pathElse);
        }

    }

    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(WhileStatement* stmt)
{
    CyFlowDotNode *node;
    CyFlowDotEdge* edge;

    node = CyFlowDotNode::factory(stmt);
    edge = this->_path->push(node);
    //edge->setProperty("headlabel", stmt->toString());
    edge->setHeadLabel(stmt->toString());

    return CyVisitor::VISIT_CONTINUE;
}

void CyFlowVisitor::leave(WhileStatement* stmt)
{
    CyFlowDotNode *node;

    node = CyFlowDotNode::factoryLoopEnd();
    this->_path->push(node);
}

int CyFlowVisitor::visit(ForStatement* stmt)
{
    CyFlowDotNode *node;
    CyFlowDotEdge* edge;

    node = CyFlowDotNode::factory(stmt);
    edge = this->_path->push(node);
    //edge->setProperty("headlabel", stmt->toString());
    edge->setLabel(stmt->toString());

    return CyVisitor::VISIT_CONTINUE;
}

void CyFlowVisitor::leave(ForStatement* stmt)
{
    CyFlowDotNode *node;

    node = CyFlowDotNode::factoryLoopEnd();
    this->_path->push(node);
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
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ContinueStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ReturnStatement* stmt)
{
    CyFlowDotNode *node = CyFlowDotNode::factory(stmt);
    this->_path->push(node);
    return CyVisitor::VISIT_BREAK;
}

int CyFlowVisitor::visit(SwtStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(CaseStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
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

