#ifndef CYTYPES_ITERATION_STATEMENT_H
#define CYTYPES_ITERATION_STATEMENT_H

#include "Statement.h"

class WhileStatement : public Statement
{
    private:
        Expression* _expr;
        Statement*  _stmt;

    public:
        WhileStatement(unsigned int line, Expression* expr, Statement *stmt)
            : Statement(line, "While")
        {
            this->_expr = expr;
            this->_stmt = stmt;
        }

        virtual ~WhileStatement() 
        {
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        Expression* getExpression()
        {
            return this->_expr;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "while : %s\n", this->getExpression()->toString());
            len += sprintf(this->_printbuff + len, "%s", this->getStatement()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);
};

class ForStatement : public Statement
{
    private:
        Expression* _init;
        Expression* _cond;
        Expression* _loop;
        Statement*  _stmt;

    public:
        ForStatement(   unsigned int line, 
                        Expression*  init,
                        Expression*  cond,
                        Expression*  loop,
                        Statement*   stmt)
            : Statement(line, "for")
        {
            this->_init = init;
            this->_cond = cond;
            this->_loop = loop;
            this->_stmt = stmt;
        }

        virtual ~ForStatement()
        {
        }

        Expression* getInitExpression()
        {
            return this->_init;
        }

        Expression* getCondExpression()
        {
            return this->_cond;
        }

        Expression* getLoopExpression()
        {
            return this->_loop;
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "for(%s; %s; %s)\n",
                    this->getInitExpression()->toString(),
                    this->getCondExpression()->toString(),
                    this->getLoopExpression()->toString());
            len += sprintf(this->_printbuff + len, "%s", this->getStatement()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);

};


class DoStatement : public Statement
{
    private:
        Expression* _expr;
        Statement*  _stmt;

    public:
        DoStatement(unsigned int line, Statement* stmt, Expression* expr)
            : Statement(line, "Do")
        {
            this->_stmt = stmt;
            this->_expr = expr;
        }

        virtual ~DoStatement() 
        {
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        Expression* getExpression()
        {
            return this->_expr;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "Do: %s\n", this->getStatement()->toString());
            len += sprintf(this->_printbuff + len, "%s", this->getExpression()->toString());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);
};


#endif
