#ifndef CYTYPES_FLOW_DOT_GRAPH_H
#define CYTYPES_FLOW_DOT_GRAPH_H

#include "CyFlowDotNode.h"
#include "CyFlowDotEdge.h"
#include <vector>

class CyFlowDotGraph
{

    private:
        std::vector<CyFlowDotEdge*>  _edges;
        char                         _name[128];
        const char*                  _cur_node;

    public:
        CyFlowDotGraph(const char* name) 
        {
            strcpy(this->_name, name);
            this->_cur_node = NULL;
        }
        virtual ~CyFlowDotGraph(){}

        void append(CyFlowDotEdge* edge)
        {
            this->_edges.push_back(edge);
        }

        const char* getName()
        {
            return this->_name;
        }

        void setCurrentNode(const char* node)
        {
            this->_cur_node = node;
        }

        const char* getCurrentNode()
        {
            return this->_cur_node;
        }

        void saveDotFile(FILE* fp);
};


#endif
