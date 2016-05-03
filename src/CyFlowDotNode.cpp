
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

CyFlowDotNode* CyFlowDotNode::factory(SwtStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();

    node->setLabel("switch");
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "1");
    node->setProperty("height", "0.3");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(CaseStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setLabel("case");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(DefaultStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setLabel("default");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ReturnStatement* stmt)
{
    char str[512];
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
    node->setProperty("fillcolor", "#3300ff");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ForStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "trapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");
    node->setProperty("fillcolor", "#3300ff");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(BreakStatement* stmt)
{
    char str[128];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);
    node->setProperty("width", "2.0");
    node->setProperty("fillcolor", "#99ff00");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ContinueStatement* stmt)
{
    char str[128];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);
    node->setProperty("width", "2.0");
    node->setProperty("fillcolor", "#99ff00");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryLoopEnd()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "invtrapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "1.0");
    node->setProperty("height", "0.3");
    node->setProperty("fillcolor", "#3300ff");
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

void CyFlowDotNode::setLabel(const char* str)
{
    unsigned int i;
    size_t len, linechars;
    size_t charmax = 0;
    unsigned int line = 1;
    char*  ptr = this->_label;
    char   property[64];

    len = strlen(str);

    linechars = 0;
    *ptr++ = ' ';
    for ( i = 0; i < len; i++, linechars++ ) 
    {
        if ( *(str + i) == '"' )
        {
            *ptr++ = '\'';
        }
        else if ( *(str + i) == '\\')
        {
            *ptr++ = '\\';
            *ptr++ = '\\';
        }
        else if ( *(str + i) == '\n')
        {
            *ptr++ = '\\';
            *ptr++ = 'l';
            line++;

            if ( charmax < linechars )
                charmax = linechars;
            linechars = 0;
        }
        else
        {
            *ptr++ = *(str + i);
        }

        if ( linechars  > 40 && *(str + i) == ' ')
        {
            ptr += sprintf(ptr, "\\l    ");
            if ( charmax < linechars )
                charmax = linechars;
            linechars = 0;
        }
    }

    sprintf(property, "%.1f", 1 + (0.3 * line - 1));
    this->setProperty("height", property);

    if ( charmax < 40 )
    {
        this->setProperty("width", "4");
    }
    else
    {
        sprintf(property, "%.1f", charmax * 0.1);
        this->setProperty("width", property);
    }
    strcat(this->_label, "\\l");  //左寄せ
}
