#ifndef CYTYPES_SWITCH_STATMENT_H
#define CYTYPES_SWITCH_STATEMENT_H

#include "Statement.h"
#include "Expression.h"

class SwtStatement : public Statement
{
    private:
        Expression* _expr;
        Statement*  _stmt;

    public:
        SwtStatement(unsigned int line, Expression* expr, Statement* stmt)
            : Statement(line, "switch")
        {
            this->_expr = expr;
            this->_stmt = stmt;
        }
        virtual ~SwtStatement()
        {
        }

        Expression* getExpression()
        {
            return this->_expr;
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "Switch: %s\n", this->getExpression()->toString());
            len += sprintf(this->_printbuff + len, "%s", this->_stmt->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual void accept(CyVisitor* visitor);

};



class CaseStatement : public Statement
{
    private:
        Expression* _expr;
        Statement*  _stmt;

    public:
        CaseStatement(unsigned int line, Expression* expr, Statement* stmt)
            : Statement(line, "case")
        {
            this->_expr = expr;
            this->_stmt = stmt;
        }
        virtual ~CaseStatement()
        {
        }

        Expression* getExpression()
        {
            return this->_expr;
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, ":%s\n", this->getExpression()->toString());
            len += sprintf(this->_printbuff + len, "%s", this->_stmt->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual void accept(CyVisitor* visitor);

};

#endif
