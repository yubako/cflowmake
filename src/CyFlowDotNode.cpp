
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
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");
    node->setProperty("fillcolor", "#CFA7CD");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryConfluenceNode()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");
    node->setProperty("fillcolor", "#CFA7CD");

    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(SwtStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();

    node->setLabel("switch");
    node->setProperty("shape", "diamond");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");

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
    node->setProperty("fillcolor", "#d7e7af");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(WhileStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "trapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ForStatement* stmt)
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "trapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(BreakStatement* stmt)
{
    char str[128];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);
    node->setProperty("width", "3.5");
    node->setProperty("fillcolor", "#d7e7af");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factory(ContinueStatement* stmt)
{
    char str[128];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "%d: %s", stmt->getLine(), stmt->toString());
    node->setLabel(str);
    node->setProperty("width", "3.5");
    node->setProperty("fillcolor", "#d7e7af");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryLoopEnd()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "invtrapezium");
    node->setProperty("style", "filled");
    node->setProperty("width", "0.6");
    node->setProperty("height", "0.2");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryVertexNode()
{
    CyFlowDotNode* node = new CyFlowDotNode();
    node->setProperty("shape", "point");
    node->setProperty("width", "0.05");
    node->setProperty("height", "0.05");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryStartNode()
{
    char str[64];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "start");
    node->setLabel(str);
    node->setProperty("width", "1");
    return node;
}

CyFlowDotNode* CyFlowDotNode::factoryEndNode()
{
    char str[64];
    CyFlowDotNode* node = new CyFlowDotNode();
    sprintf(str, "end");
    node->setLabel(str);
    node->setProperty("width", "1");
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
        else if ( *(str + i) == '%')
        {
            *ptr++ = '%';
            *ptr++ = '%';
        }
        else if ( *(str + i) == '\n')
        {
            ptr += sprintf(ptr, "\\l    ");
            if ( charmax < linechars )
                charmax = linechars;
            linechars = 0;
            line++;
        }
        else
        {
            *ptr++ = *(str + i);
        }

        //if ( linechars  > 30 &&
        //        (  ( *(str + i) == ';' )
        //        || ( *(str + i) == ',') || ( *(str + i) == '\n') 
        //        || ( *(str + i) == '.') || ( *(str + i) == '=' ) 
        //        || ( *(str + i) == '|') || ( *(str + i) == '&' ) ) )
        //{
        //    ptr += sprintf(ptr, "\\l        ");
        //    if ( charmax < linechars )
        //        charmax = linechars;
        //    linechars = 0;
        //    line++;
        //}
    }
    if ( charmax < linechars )
        charmax = linechars;

    sprintf(property, "%.1f", 1 + (0.3 * line - 1));
    this->setProperty("height", property);

    if ( charmax < 20 )
    {
        this->setProperty("width", "2.5");
    }
    else if ( charmax < 30 )
    {
        this->setProperty("width", "3");
    }
    else if ( charmax < 40 )
    {
        this->setProperty("width", "5");
    }
    else
    {
        sprintf(property, "%.1f", charmax * 0.1);
        this->setProperty("width", property);
    }
    strcat(this->_label, "\\l");  //左寄せ
}


