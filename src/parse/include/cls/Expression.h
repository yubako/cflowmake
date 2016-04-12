#ifndef CYTYPES_EXPRESSION_H
#define CYTYPES_EXPRESSION_H


#include "SourceLocation.h"

class NullExpression;
class Expression : public SourceLocation
{

    private:
        Expression*     _sibling;
        char            _printbuff[1024];

    public:

        Expression(unsigned int line, const char* str)
            : SourceLocation(line, str)
        {
            this->_sibling = NULL;
            printf("Expression: %s\n", str);
        }
        virtual ~Expression() { }

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

        int hasNextSibling()
        {
            if ( this->_sibling && this->_sibling->isNull() == 0 )
                return 1;
            return 0;
        }
        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff, "%s ", this->getCodeString());
            if ( this->hasNextSibling() ) 
                len += sprintf(this->_printbuff + len, " %s", this->getNextSibling()->toString());

            return this->_printbuff;
        }

        virtual int isNull()
        {
            return 0;
        }
};

class NullExpression : public Expression
{
    public:
        NullExpression()
            : Expression(0, "Null")
        {
        }
        virtual ~NullExpression()
        {
        }

        virtual int isNull()
        {
            return 1;
        }

};



#endif

