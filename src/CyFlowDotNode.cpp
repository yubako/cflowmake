
#include "pars/cytypes.h"
#include "vst/CyFlowDotNode.h"
#include "vst/CyFlowDotEdge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>

// static
std::vector<CyFlowDotEdge*> CyFlowDotEdge::_edge_all;
std::vector<CyFlowDotNode*> CyFlowDotNode::_node_all;
unsigned int                CyFlowDotNode::_serial = 0;


CyFlowDotNode* CyFlowDotNode::factory()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    return node;
}
CyFlowDotNode* CyFlowDotNode::factory(const char* str)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setLabel(str);
    return node;

}
CyFlowDotNode* CyFlowDotNode::factory(ExpressionStatement* stmt)
{
    char str[1024];
    CyFlowDotNode* node = new CyFlowDotNode();

    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(IfStatement* stmt)
{
    //char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();

    //sprintf(str, "%d: IF( %s )", stmt->getLine(), stmt->toString());
    //node->setLabel(str);
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "1");
    node->setProperty("height", "0.3");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryConfluenceNode()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ReturnStatement* stmt)
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(WhileStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "trapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ForStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "trapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryLoopEnd()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "invtrapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryVertexNode()
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "point");
    node->setProperty("width", "0.1");
    node->setProperty("height", "0.1");
    return node;
}

