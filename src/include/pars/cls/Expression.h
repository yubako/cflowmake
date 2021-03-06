#ifndef CYTYPES_EXPRESSION_H
#define CYTYPES_EXPRESSION_H

#include "SourceLocation.h"

class CyVisitor;
class NullExpression;
class Expression : public SourceLocation
{

    private:
        Expression*     _sibling;

    public:

        Expression(unsigned int line, const char* str)
            : SourceLocation(line, str)
        {
            this->_sibling = NULL;
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
            unsigned int line = this->getLine();
            len += sprintf(this->_printbuff + len, "%s", this->getCodeString());

            if ( strcmp(this->getCodeString(), ",") == 0 )
            {
                len += sprintf(this->_printbuff + len, " ");
            }

            if ( this->hasNextSibling() ) 
            {
                if ( this->getNextSibling()->getLine() > line )
                {
                    len += sprintf(this->_printbuff + len, "\n    ");
                }
                len += sprintf(this->_printbuff + len, "%s", this->getNextSibling()->toString());
            }
            return this->_printbuff;
        }

        virtual int isNull()
        {
            return 0;
        }

        /**
         * @override 
         */
        virtual int accept(CyVisitor* visitor);
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

        /**
         * @override 
         */
        virtual int accept(CyVisitor* visitor);
};



#endif

