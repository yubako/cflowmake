#ifndef CYTYPES_DOT_H
#define CYTYPES_DOT_H

#include "pars/cytypes.h"
#include <vector>
#include <string>
#include <map>

class CyFlowDotNode 
{

    private:
        static std::vector<CyFlowDotNode*> _node_all;
        static unsigned int _serial;
        char                _str[512];
        char                _label[512];
        unsigned int        _id;


    protected:
        std::map<std::string, std::string> _property;
        char _name[32];

        CyFlowDotNode()
        {
            this->_label[0]  = '\0';
            this->_id   = CyFlowDotNode::_serial ++;

            sprintf(this->_name, "Node_%u", this->_id);
            CyFlowDotNode::_node_all.push_back(this);
        }

    public:

        virtual ~CyFlowDotNode() {}

        static CyFlowDotNode* factory();
        static CyFlowDotNode* factory(const char* str);
        static CyFlowDotNode* factory(ExpressionStatement* stmt);
        static CyFlowDotNode* factory(IfStatement* stmt);
        static CyFlowDotNode* factory(ReturnStatement* stmt);
        static CyFlowDotNode* factory(ForStatement* stmt);
        static CyFlowDotNode* factory(WhileStatement* stmt);
        static CyFlowDotNode* factoryLoopEnd();
        static CyFlowDotNode* factoryVertexNode();
        static CyFlowDotNode* factoryConfluenceNode();


        static unsigned int nodeDefaultDefine(char* str)
        {
            std::map<std::string, std::string> property;
            property["shape"]      = "box";
            property["color"]      = "#000000";
            property["fillcolor"]  = "#e6e6fa"; /* lavender */
            property["style"]      = "filled, rounded";
            property["fixedsize"]  = "true";
            property["fontsize"]   = "11";
            property["fontcolor"]  = "#000000";
            //property["height"]     = "0.5";
            property["width"]      = "3.0";

            unsigned int len = 0;
            len += sprintf(str + len, "node [\n");
            for ( std::map<std::string, std::string>::iterator it = property.begin();
                    it != property.end(); it ++)
            {
                len += sprintf(str + len, "    %s = \"%s\",\n", it->first.c_str(), it->second.c_str());
            }

            len += sprintf(str + len, "];\n");

            return len;
        }

        const char* getNodeName()
        {
            return this->_name;
        }

        void setProperty(const char* name, const char* value)
        {
            this->_property[name] = value;
        }

        void setLabel(const char* str)
        {
            unsigned int i;
            size_t len, linechars;
            unsigned int line = 1;
            char*  ptr = this->_label;
            char   property[32];
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
                }else
                {
                    *ptr++ = *(str + i);
                }

                if ( linechars  > 40 
                        && *(str + i) == ' '
                        && len - i > 5)
                {
                    ptr += sprintf(ptr, "\\l        ");
                    linechars = 0;
                    line++;
                }
            }

            sprintf(property, "%.1f", 0.4 * line);
            this->setProperty("height", property);
            if ( line > 1)
            {
                this->setProperty("width", "3.5");
            }
            strcat(this->_label, "\\l");  //左寄せ
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_str + len, "%-10s [", this->getNodeName());
            for ( std::map<std::string, std::string>::iterator it = this->_property.begin();
                    it != this->_property.end(); it ++)
            {
                len += sprintf(this->_str + len, "%s = \"%s\",", it->first.c_str(), it->second.c_str());
            }

            len += sprintf(this->_str + len, "label = \"%s\"" , this->_label);
            len += sprintf(this->_str + len, "]\n");

            return this->_str;
        }

};


#endif

