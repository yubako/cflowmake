#ifndef CYTYPES_FLOW_DOT_GRAPH_H
#define CYTYPES_FLOW_DOT_GRAPH_H

#include "CyFlowDotNode.h"
#include "CyFlowDotEdge.h"
#include <vector>

class CyFlowPath
{
    private:
        CyFlowDotNode*              _entrance;
        std::vector<CyFlowDotNode*> _nodes;
        std::vector<CyFlowDotEdge*> _edges;
        const char*                 _cur_node;

    public:
        CyFlowPath(CyFlowDotNode* node)
        {
            CyFlowDotNode* entrance;

            /* Pathの起点を作成 */
            entrance = CyFlowDotNode::factoryVertexNode();
            this->_entrance = entrance;
            this->_cur_node = entrance->getNodeName();
            this->_nodes.push_back(entrance);

            if ( node ) 
            {
                this->moveToSameNode(node);
            }
        }
        ~CyFlowPath()
        { }

        CyFlowDotEdge* moveToSameNode(CyFlowDotNode* from)
        {
            CyFlowDotEdge* edge = CyFlowDotEdge::factory(from->getNodeName(), this->getCurrentNode());
            edge->setSame();
            this->_edges.push_back(edge);
            return edge;
        }

        CyFlowDotEdge* getLastEdge()
        {
            return this->_edges.at(this->_edges.size() - 1);
        }

        void push(CyFlowDotNode* node)
        {
            CyFlowDotEdge* edge = CyFlowDotEdge::factory(this->getCurrentNode(), node->getNodeName());
            edge->setProperty("weight", "2");
            this->_edges.push_back(edge);
            this->_nodes.push_back(node);
            this->_cur_node = node->getNodeName();
        }

        const char* getCurrentNode()
        {
            return this->_cur_node;
        }

        void close(CyFlowDotNode* confluence)
        {
            /* 終点ノードの作成 */
            CyFlowDotNode* fin  = CyFlowDotNode::factoryVertexNode();
            this->push(fin);

            /* 引数と連結 */
            if ( confluence )
            {
                this->moveToSameNode(confluence)->setProperty("dir", "back");
            }
        }

        size_t save(char* str)
        {
            unsigned int len = 0;

            /* node 定義 */
            len += sprintf(str + len, "\n\n\n");
            std::vector<CyFlowDotNode*>::iterator it;
            for ( it = this->_nodes.begin(); it != this->_nodes.end(); it++ ) 
            {
                CyFlowDotNode* node = *it;
                len += sprintf(str + len, "%s", node->toString());
            }

            len += sprintf(str + len, "\n\n");

            /* edge ダンプ */
            std::vector<CyFlowDotEdge*>::iterator jt;
            for ( jt = this->_edges.begin(); jt != this->_edges.end(); jt++ )
            {
                CyFlowDotEdge* edge = *jt;
                len += sprintf(str + len, "%s", edge->toString());
            }
            return len;
        }
};

class CyFlowDotGraph
{
    private:
        char                        _name[128];
        std::vector<CyFlowPath*>    _paths;

    public:
        CyFlowDotGraph(const char* name) 
        {
            strcpy(this->_name, name);
        }
        virtual ~CyFlowDotGraph(){}

        const char* getName()
        {
            return this->_name;
        }

        CyFlowPath* createPath(CyFlowDotNode* sameNode)
        {
            CyFlowPath* path = new CyFlowPath(sameNode);
            this->_paths.push_back(path);
            return path;
        }

        void saveDotFile(FILE* fp);
};


#endif
