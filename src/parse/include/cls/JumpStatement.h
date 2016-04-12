#ifndef CYTYPES_JUMP_STATEMENT_H
#define CYTYPES_JUMP_STATEMENT_H

#include "Statement.h"

class GotoStatement : public Statement
{

    private:
        const char* _identifier;


    public:
        GotoStatement(unsigned int line, const char* identifier) 
            : Statement(line, "goto")
        {
            this->_identifier = identifier;
        }
        virtual ~GotoStatement()
        {
        }

        const char* getIdentifier()
        {
            return this->_identifier;
        }

        const char* toString()
        {
            sprintf(this->_printbuff, "goto: %s", this->_identifier);
            return this->_printbuff;
        }
};

class LabeledStatement : public Statement
{
    private:
        const char* _identifier;
        Statement*  _stmt;


    public:
        LabeledStatement(unsigned int line, const char* label, Statement *stmt) 
            : Statement(line, "LabeledStatement")
        {
            this->_identifier = label;
            this->_stmt       = stmt;
        }

        virtual ~LabeledStatement()
        {
        }

        const char* getIdentifier()
        {
            return this->_identifier;
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "%s:\n", this->getIdentifier());
            len += sprintf(this->_printbuff + len, "%s", this->getStatement()->toString());
            return this->_printbuff;
        }

};

class BreakStatement: public Statement
{
    public:
        BreakStatement(unsigned int line) : Statement(line, "break")
        {
        }
        virtual ~BreakStatement()
        {
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "break;");
            return this->_printbuff;
        }
};

class ContinueStatement: public Statement
{
    public:
        ContinueStatement(unsigned int line) : Statement(line, "continue")
        {
        }
        virtual ~ContinueStatement()
        {
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "continue;");
            return this->_printbuff;
        }
};

class ReturnStatement : public Statement
{
    private:
        Expression* _expr;

    public:
        ReturnStatement(unsigned int line)
            : Statement(line, "ReturnStatement")
        {
            this->_expr = new NullExpression();
        }

        virtual ~ReturnStatement()
        {
        }

        void setExpression(Expression* expr)
        {
            this->_expr = expr;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "return");
            if ( ! this->_expr->isNull() )
            {
                len += sprintf(this->_printbuff + len, " %s", this->_expr->toString());
            }
            return this->_printbuff;
        }

};


#endif
