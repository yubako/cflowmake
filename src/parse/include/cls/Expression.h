#ifndef CYTYPES_EXPRESSION_H
#define CYTYPES_EXPRESSION_H


#include "SourceLocation.h"

class Expression : public SourceLocation
{

    private:
        Expression*     _sibling;
        char            _printbuff[1024];

    public:

        Expression(unsigned int line, const char* str) : SourceLocation(line, str)
        {
            this->_sibling = NULL;
//            printf("Expression: %u:%s\n", line, str);
        }

        virtual ~Expression()
        {
        }

        void pushSibling(class Expression* exp)
        {
            Expression* sibling = this;
            while ( sibling->getNextSibling() )
            {
                sibling = sibling->getNextSibling();
            }
            sibling->_sibling = exp;
        }

        Expression* getNextSibling()
        {
            return this->_sibling;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff, "%s ", this->getCodeString());
            if ( this->_sibling) 
                len += sprintf(this->_printbuff + len, ", %s", this->_sibling->toString());

            return this->_printbuff;
        }
};



#endif

