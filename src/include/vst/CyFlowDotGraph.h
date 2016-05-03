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
                this->moveToSameNode(node)->setProperty("dir", "none");
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

        CyFlowDotEdge* push(CyFlowDotNode* node)
        {
            CyFlowDotEdge* edge = CyFlowDotEdge::factory(this->getCurrentNode(), node->getNodeName());
            edge->setProperty("weight", "100");
            this->_edges.push_back(edge);
            this->_nodes.push_back(node);
            this->_cur_node = node->getNodeName();
            return edge;
        }

        CyFlowDotEdge* push(const char* from, const char* to)
        {
            CyFlowDotEdge* edge = CyFlowDotEdge::factory(from, to);
            this->_edges.push_back(edge);
            return edge;
        }

        size_t nodeCount()
        {
            return this->_nodes.size();
        }

        CyFlowDotNode* get(size_t idx)
        {
            return this->_nodes[idx];
        }

        CyFlowPath* branch(CyFlowDotNode* base)
        {
            size_t i;
            CyFlowDotEdge* edge;
            CyFlowPath* path = new CyFlowPath(this->get(0));

            for ( i = 0; i < this->nodeCount() -1; i++ )
            {
                path->push(CyFlowDotNode::factory());
            }

            /* 分岐点をつくる */
            path->push(base);
            edge = path->push(CyFlowDotNode::factoryVertexNode());
            edge->setSame();
            return path;
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

        void push(CyFlowPath* path)
        {
            this->_paths.push_back(path);
        }

        static unsigned int graphDefaultDefine(char* str)
        {
            std::map<std::string, std::string> property;
            property["bgcolor"]      = "#aaaaaa";
            property["labelloc"]     = "t";
            property["splines"]      = "false"; /* 曲線は使わない */

            unsigned int len = 0;
            len += sprintf(str + len, "graph [\n");
            for ( std::map<std::string, std::string>::iterator it = property.begin();
                    it != property.end(); it ++)
            {
                len += sprintf(str + len, "    %s = \"%s\",\n", it->first.c_str(), it->second.c_str());
            }

            len += sprintf(str + len, "];\n");

            return len;
        }

        void saveDotFile(const char* fpath);
};


#endif
