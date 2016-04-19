
#include "vst/CyFlowVisitor.h"

#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>

using namespace std;


// --------------------------------------------------------------------------
int CyFlowVisitor::visit(FunctionDefinition* decl)
{
    CyFlowDotGraph  *graph = new CyFlowDotGraph(decl->toString());
    this->_graph = graph;
    this->_graphs.push_back(this->_graph);

    /* 起点を作成 */
    CyFlowDotNode *node = CyFlowDotNode::factoryVertexNode();
    this->_graph->setCurrentNode(node->getNodeName());

    return CyVisitor::VISIT_CONTINUE;
}

void CyFlowVisitor::leave(FunctionDefinition* decl)
{
    /* 終点を作成 */
    CyFlowDotNode *node = CyFlowDotNode::factoryVertexNode();
    CyFlowDotEdge* edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), node->getNodeName());
    this->_graph->append(edge);
    this->_graph->setCurrentNode(node->getNodeName());
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
    CyFlowDotEdge *edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), node->getNodeName());
    this->_graph->append(edge);
    this->_graph->setCurrentNode(node->getNodeName());
    return CyVisitor::VISIT_CONTINUE;
}

int CyFlowVisitor::visit(IfStatement* stmt)
{
    int ope;
    CyFlowDotEdge *edge;
    CyFlowDotNode *node;
    CyFlowDotNode *vertex;
    
    node = CyFlowDotNode::factory(stmt);
    edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), node->getNodeName());
    this->_graph->append(edge);

    /* 分岐頂点追加 */
    vertex = CyFlowDotNode::factoryVertexNode();
    edge   = CyFlowDotEdge::factory(node->getNodeName(), vertex->getNodeName());
    edge->setSame();
    this->_graph->append(edge);

    /* 合流地点を作成 */
    CyFlowDotNode *confluence = CyFlowDotNode::factoryConfluenceNode();

    /* true */
    this->_graph->setCurrentNode(node->getNodeName());
    ope = stmt->getTrue()->accept(this);
    if ( ope == CyFlowVisitor::VISIT_CONTINUE)
    {
        edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), confluence->getNodeName());
        this->_graph->append(edge);
    }
    else
    {
        edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), confluence->getNodeName());
        this->_graph->append(edge);
    }

    /* false */
    this->_graph->setCurrentNode(vertex->getNodeName());
    ope = stmt->getElse()->accept(this);
    if ( ope == CyFlowVisitor::VISIT_CONTINUE)
    {
        edge = CyFlowDotEdge::factory(confluence->getNodeName(), this->_graph->getCurrentNode());
        edge->setSame();
        edge->setProperty("dir", "back");
        this->_graph->append(edge);
    }
    else
    {
        edge = CyFlowDotEdge::factory(confluence->getNodeName(), this->_graph->getCurrentNode());
        edge->setSame();
        edge->setProperty("dir", "back");
        printf("graph edge dir %s\n", confluence->getNodeName());
        this->_graph->append(edge);
    }

    /* 合流地点から継続 */
    this->_graph->setCurrentNode(confluence->getNodeName());
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
    CyFlowDotEdge *edge = CyFlowDotEdge::factory(this->_graph->getCurrentNode(), node->getNodeName());
    this->_graph->append(edge);
    this->_graph->setCurrentNode(node->getNodeName());
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
    FILE* fp;
    unsigned int len = 0;
    char buffer[4096];
    char* str;

    len += sprintf(buffer + len, "digraph cflowchart {\n\n");
    len += CyFlowDotEdge::edgeDefaultDefine(buffer + len);
    len += CyFlowDotNode::nodeDefaultDefine(buffer + len);
    len += CyFlowDotNode::nodeDefinition(buffer + len);

    printf(buffer);

    std::vector<CyFlowDotGraph*>::iterator it;
    for ( it = this->_graphs.begin(); it != this->_graphs.end(); it++ )
    {
        CyFlowDotGraph* graph = *it;
        graph->saveDotFile(fp);
    }

    len += sprintf(buffer + len, "}\n\n");
}

