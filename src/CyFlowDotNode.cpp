
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
unsigned int           CyFlowDotNode::_serial = 0;


CyFlowDotNode* CyFlowDotNode::factory()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    return node;

}
CyFlowDotNode* CyFlowDotNode::factory(ExpressionStatement* stmt)
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();

    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(IfStatement* stmt)
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();

    sprintf(str, "%d: IF( %s )", stmt->getLine(), stmt->toString());
    node->setLabel(str);
    node->setProperty("shape", "diamond");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryConfluenceNode()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "diamond");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ReturnStatement* stmt)
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();

    sprintf(str, "%d: return", stmt->getLine());
    node->setLabel(str);

    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryVertexNode()
{
    char str[256];
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "point");
    return node;
}

