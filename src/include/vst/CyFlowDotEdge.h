#ifndef CYTYPES_FLOW_DOT_EDGE_H
#define CYTYPES_FLOW_DOT_EDGE_H

#include <map>
#include <vector>

class CyFlowDotEdge
{
    private:
        static std::vector<CyFlowDotEdge*>        _edge_all;

        CyFlowDotEdge()
        {
            this->_from = NULL;
            this->_to   = NULL;
            this->_same = 0;
        }

    protected:
        char           _str[512];
        std::map<std::string, std::string> _property;

        const char*    _from;       /* 元   */
        const char*    _to;         /* 先   */
        unsigned int   _same;       /* same */

    public:

        virtual ~CyFlowDotEdge() { }

        static CyFlowDotEdge* factory(const char* from, const char* to)
        {
            CyFlowDotEdge* edge = new CyFlowDotEdge();
            CyFlowDotEdge::_edge_all.push_back(edge);

            edge->_from = from;
            edge->_to   = to;
            return edge;
        }

        /**
         * edge default
         */
        static unsigned int edgeDefaultDefine(char* str)
        {
            unsigned int len = 0;
            std::map<std::string, std::string> property;

            property["fontsize"]  = "11";
            property["fontcolor"] = "#000000";
            property["fontname"]  = "MS Gothic";
            property["fillcolor"] = "#0000ff";

            len += sprintf(str + len, "edge [\n");
            for ( std::map<std::string, std::string>::iterator it = property.begin();
                    it != property.end(); it ++)
            {
                len += sprintf(str + len, "    %s = \"%s\",\n", it->first.c_str(), it->second.c_str());
            }

            len += sprintf(str + len, "];\n");
            return len;
        }

        std::map<std::string, std::string> getProperty()
        {
            return this->_property;
        }

        void setProperty(std::string name, std::string value)
        {
            this->_property[name] = value;
        }

        virtual const char* toString()
        {
            unsigned int len = 0;

            len += sprintf(this->_str + len, "%s -> %s ", this->_from, this->_to);
            if ( this->_property.size() > 0 )
            {
                len += sprintf(this->_str + len, " [");
                for ( std::map<std::string, std::string>::iterator it = this->_property.begin();
                        it != this->_property.end(); it ++)
                {
                    len += sprintf(this->_str + len, " %s = \"%s\",", it->first.c_str(), it->second.c_str());
                }

                len += sprintf(this->_str + len, "]");
            }
            len += sprintf(this->_str + len, ";\n");

            if ( this->_same )
            {
                len += sprintf(this->_str + len, "{rank = same; %s; %s}\n", this->_from, this->_to);
            }
            return this->_str;
        }

        void setSame()
        {
            this->_same = 1;
        }

        const char* mk_labelstring(const char* str)
        {
            unsigned int i;
            size_t linechars;

            size_t len = strlen(str);
            char* buffer = new char[len * 2];
            char* ptr = buffer;

            linechars = 0;
            *ptr++ = ' ';
            for ( i = 0; i < len; i++ , linechars++ ) 
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

                if ( linechars  > 40 && *(str + i) == ' ')
                {
                    ptr += sprintf(ptr, "\\l    ");
                    linechars = 0;
                }
            }

            ptr += sprintf(ptr, "\\l");
            return buffer;
        }
        void setTailLabel(const char* str)
        {
            this->setProperty("taillabel", this->mk_labelstring(str));
        }

        void setHeadLabel(const char* str)
        {
            this->setProperty("headlabel", this->mk_labelstring(str));
        }

        void setLabel(const char* str)
        {
            this->setProperty("label", this->mk_labelstring(str));
        }

};



#endif
