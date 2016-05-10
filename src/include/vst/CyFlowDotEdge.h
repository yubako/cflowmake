#ifndef CYTYPES_FLOW_DOT_EDGE_H
#define CYTYPES_FLOW_DOT_EDGE_H

#include <map>
#include <vector>

class CyFlowDotEdge
{
    private:
        static std::vector<CyFlowDotEdge*>        _edge_all;
        char                                      _frompos[16];
        char                                      _topos[16];

        CyFlowDotEdge()
        {
            this->_from = NULL;
            this->_to   = NULL;
            this->_same = 0;
            this->_frompos[0] = '\0';
            this->_topos[0]   = '\0';
        }

    protected:
        char           _str[4096];
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

            property["fontsize"]   = "12";
            property["fontcolor"]  = "#333333";
            property["fontname"]   = "NSimSun";
            property["fillcolor"]  = "#929994";

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

        void setFromPositionLeft()   { strcpy(this->_frompos, ":w"); }
        void setFromPositionRight()  { strcpy(this->_frompos, ":e"); }
        void setFromPositionBottom() { strcpy(this->_frompos, ":s"); }
        void setToPositionLeft()     { strcpy(this->_topos  , ":w"); }
        void setToPositionRight()    { strcpy(this->_topos  , ":e"); }

        virtual const char* toString()
        {
            unsigned int len = 0;

            len += sprintf(this->_str + len, "%s%s ", this->_from, this->_frompos);
            len += sprintf(this->_str + len, " -> %s%s ", this->_to, this->_topos);

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

        const char* mk_labelstring(const char* str )
        {
            unsigned int i;
            size_t linechars, charmax = 0;

            size_t len = strlen(str);
            char* buffer = new char[len * 2];
            char* ptr = buffer;

            linechars = 0;
            *ptr++ = ' ';
            for ( i = 0; i < len; i++ , linechars++ ) 
            {
                if ( *(str + i) == '\\')
                {
                    *ptr++ = '\\';
                    *ptr++ = '\\';
                }else if ( *(str + i) == '\n')
                {
                    ptr += sprintf(ptr, "\\l    ");
                    if ( charmax < linechars )
                        charmax = linechars;
                    linechars = 0;
                }
                else
                {
                    *ptr++ = *(str + i);
                }

                //if ( linechars  > 20 &&
                //        (  ( *(str + i) == ';' )
                //        || ( *(str + i) == ',') || ( *(str + i) == '\n') 
                //        || ( *(str + i) == '.') || ( *(str + i) == '=' ) 
                //        || ( *(str + i) == '|') || ( *(str + i) == '&' ) ) )
                //{
                //    ptr += sprintf(ptr, "\\l    ");

                //    if ( charmax < linechars )
                //        charmax = linechars;

                //    linechars = 0;
                //}
            }

            ptr += sprintf(ptr, "\\l");
            return buffer;
        }

        void setHeadLabel(const char* str)
        {
            //size_t chars;
            //char   buff[128];
            this->setProperty("headlabel", this->mk_labelstring(str));
            //sprintf(buff, "%0.1f", chars/(double)2);
            //this->setProperty("labeldistance", buff);
        }
};



 #endif
