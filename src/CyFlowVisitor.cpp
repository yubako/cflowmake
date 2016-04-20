
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

    printf("visit function %s\n", decl->toString());
    return CyVisitor::VISIT_CONTINUE;
}

void CyFlowVisitor::leave(FunctionDefinition* decl)
{
    printf("leave function %s\n", decl->toString());
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
    stmt->getStatement()->accept(this);
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
    int ope;
    CyFlowDotEdge *edge;
    CyFlowDotNode *node, *confluence;
    CyFlowPath    *pathTrue, *pathElse;
    
    node = CyFlowDotNode::factory(stmt);
    edge = this->_path->push(node);
    edge->setProperty("label", stmt->toString());

    /* true */
    ope = stmt->getTrue()->accept(this);

    /* 合流地点を作成 */
    confluence = CyFlowDotNode::factoryConfluenceNode();
    this->_path->push(confluence);

    /* 分岐追加 */
    pathElse = this->_graph->createPath(node);
    pathTrue = this->pathSwitch(pathElse);

    /* else */
    this->_path->getLastEdge()->setProperty("label", "False");
    ope = stmt->getElse()->accept(this);

    /* elseパス終了 */
    pathElse->close(confluence);


    /* 合流地点から継続 */
    this->pathSwitch(pathTrue);
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(WhileStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(ForStatement* stmt)
{
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

