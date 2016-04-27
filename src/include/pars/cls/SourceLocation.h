#ifndef CYTYPES_SOURCE_LOCATION_H
#define CYTYPES_SOURCE_LOCATION_H

#include <string.h>
#include <stdio.h>

class CyVisitor;
class SourceLocation
{
    private:
        unsigned int _line;
        char        *_str;

    protected:
        char         _printbuff[8192];

    public:
        SourceLocation(unsigned int line, const char* str)
        {
            size_t len = strlen(str);
            this->_line = line;
            this->_str = new char[len + 1];
            strcpy(this->_str, str);
        }
        virtual ~SourceLocation(){
            if ( this->_str )
            {
                delete[] this->_str;
                this->_str = NULL;
            }
        }

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

        /**
         * @override 
         */
        virtual int accept(CyVisitor* visitor) = 0;

};


#endif

