#ifndef CYTYPTES_STATEMENT_H
#define CYTYPTES_STATEMENT_H

#include "SourceLocation.h"
#include "Expression.h"

class Statement : public SourceLocation
{
    private:
        int _type;

    protected:
        Statement*      _sibling;

    public:

        Statement(unsigned int line, const char* str)
            : SourceLocation(line, str)
        {
            this->_sibling = NULL;
        }

        virtual ~Statement(){}

        Statement* getNextSibling()
        {
            return this->_sibling;
        }

        int hasNextSibling()
        {
            if ( this->_sibling ) 
                return 1;
            return 0;
        }

        void pushSibling(Statement* stmt)
        {
            Statement* sibling = this;
            while ( sibling->hasNextSibling() )
            {
                sibling = sibling->getNextSibling();
            }
            sibling->_sibling = stmt;
        }

        virtual int isNull()
        {
            return 0;
        }

};

class NullStatement: public Statement
{
    public:
        NullStatement() : Statement(0, "Null")
        {
        }
        virtual ~NullStatement()
        {
        }

        virtual int isNull()
        {
            return 1;
        }
};


#endif
