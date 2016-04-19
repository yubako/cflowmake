#ifndef CYTYPES_EXPRESSION_STATEMENT_H
#define CYTYPES_EXPRESSION_STATEMENT_H

#include "Statement.h"

class ExpressionStatement : public Statement
{

    private:
        Expression* _expr;

    public:
        ExpressionStatement(unsigned int line, Expression* expr)
            : Statement(line, "ExpressionStatement")
        {
            this->_expr = expr;
        }
        virtual ~ExpressionStatement()
        {
            delete this->_expr;
        }

        Expression* getExpression()
        {
            return this->_expr;
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "%s", this->getExpression()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);
};





#endif

