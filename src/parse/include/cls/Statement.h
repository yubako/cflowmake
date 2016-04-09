#ifndef CYTYPTES_STATEMENT_H
#define CYTYPTES_STATEMENT_H

#include "SourceLocation.h"
#include "Expression.h"

class Statement : public SourceLocation
{
    private:
        int _type;

    protected:
        char            _printbuff[1024];
        Statement*      _sibling;

        void setStatementType(int type)
        {
            this->_type = type;
        }

    public:

        static const int STMTTYPE_EXPRESSION = 1;
        static const int STMTTYPE_IF = 2;

        Statement(unsigned int line, const char* str) : SourceLocation(line, str)
        {
            this->_sibling = NULL;
        }
        virtual ~Statement(){}

        virtual int getStatementType()
        {
            return this->_type;
        }
};


class NullStatement: public Statement
{
    public:
        NullStatement() : Statement(0, "NullStatement")
        {
            ;
        }
        virtual ~NullStatement()
        {
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "NullStmt : %s \n", this->getCodeString());
            return this->_printbuff;
        }
};

class ExpressionStatement : public Statement
{

    private:
        Expression* _exp;

    public:
        ExpressionStatement(unsigned int line, Expression* exp) 
            : Statement(line, "ExpressionStatement")
        {
            this->_exp = exp;
            this->setStatementType(Statement::STMTTYPE_EXPRESSION);
        }
        virtual ~ExpressionStatement()
        {
            delete this->_exp;
        }

        Expression* getExpression()
        {
            return this->_exp;
        }

        virtual const char* toString()
        {
            sprintf(this->_printbuff, "ExprStmt : %s \n", this->getExpression()->toString());
            return this->_printbuff;
        }
};



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

            this->setStatementType(Statement::STMTTYPE_IF);
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

        virtual const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "\nIf   : %s \n", this->getExpression()->toString());
            len += sprintf(this->_printbuff + len, "True : %s", this->_trueStmt->toString());
            len += sprintf(this->_printbuff + len, "Else : %s", this->_elseStmt->toString());
            return this->_printbuff;
        }

};


#endif
