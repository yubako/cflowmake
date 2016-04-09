#ifndef CYTYPES_SOURCE_LOCATION_H
#define CYTYPES_SOURCE_LOCATION_H

#include <string.h>

class SourceLocation
{
    private:
        unsigned int _line;
        char         _str[1024];
        char         _printbuff[1024];

    public:
        SourceLocation(unsigned int line, const char* str)
        {
            this->_line = line;
            strcpy(this->_str, str);
        }

        ~SourceLocation(){}

        const char* getCodeString()
        {
            return this->_str;
        }

        unsigned int getLine()
        {
            return this->_line;
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "%4u: %s", this->_line, this->_str); 
            return this->_printbuff;
        }

};


#endif

