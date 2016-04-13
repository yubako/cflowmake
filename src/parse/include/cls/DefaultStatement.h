#ifndef CYTYPES_DEFAULT_STATEMENT_H
#define CYTYPES_DEFAULT_STATMENET_H

#include "Statement.h"

class DefaultStatement: public Statement
{
    private:
        Statement *_stmt;

    public:
        DefaultStatement(unsigned int line, Statement *stmt) : Statement(line, "break")
        {
            this->_stmt = stmt;
        }
        virtual ~DefaultStatement()
        {
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "%s", this->getStatement()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual void accept(CyVisitor* visitor);
};


#endif

