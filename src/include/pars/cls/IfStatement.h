#ifndef CYTYPES_IF_STATEMENT_H
#define CYTYPES_IF_STATEMENT_H


#include "Statement.h"

class IfStatement : public Statement
{

    private:
        Statement*  _trueStmt;
        Statement*  _elseStmt;
        Expression* _exp;

    public:
        IfStatement(unsigned int line, Expression* exp)
            : Statement(line, "IfStatement")
        {
            this->_exp      = exp;
            this->_trueStmt = new NullStatement();
            this->_elseStmt = new NullStatement();
        }
        virtual ~IfStatement() { 
            delete this->_exp;
        }

        void setTrue(Statement* stmt)
        {
            delete this->_trueStmt;
            this->_trueStmt = stmt;
        }

        void setElse(Statement* stmt)
        {
            delete this->_elseStmt;
            this->_elseStmt = stmt;
        }

        Expression* getExpression()
        {
            return this->_exp;
        }

        Statement* getTrue()
        {
            return this->_trueStmt;
        }

        Statement* getElse()
        {
            return this->_elseStmt;
        }

        virtual const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "%s", this->getExpression()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);


};

#endif

