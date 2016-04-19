#ifndef CYTYPES_COMPOUND_STATEMENT_H
#define CYTYPES_COMPOUND_STATMENT_H

#include "Statement.h"
#include "Declaration.h"

class CompoundStatement : public Statement
{

    private:
        Statement*   _stmt;
        Declaration* _decl;

    public:
        CompoundStatement(unsigned int line)
            : Statement(line, "CompoundStatement")
        {
            this->_stmt = new NullStatement();
            this->_decl = new NullDeclaration();
        }

        virtual ~CompoundStatement()
        {
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        void pushStatement(Statement* stmt)
        {
            if ( this->_stmt->isNull())
            {
                delete this->_stmt;
                this->_stmt = stmt;
            }
            else
            {
                this->_stmt->pushSibling(stmt);
            }
        }

        void pushDeclaration(Declaration* decl)
        {
            if (this->_decl->isNull() )
            {
                delete this->_decl;
                this->_decl = decl;
            }
            else
            {
                this->_decl->pushSibling(decl);
            }
        }

        Declaration* getDeclaration()
        {
            return this->_decl;
        }

        const char* toString()
        {
            unsigned int len = 0;
            len += sprintf(this->_printbuff + len, "{\n");

            Declaration *decl = this->getDeclaration();
            if ( !decl->isNull() )
            {
                len += sprintf(this->_printbuff + len, "Declarations:\n");
                len += sprintf(this->_printbuff + len, "%s\n", decl->toString());
                while ( decl->hasNextSibling() )
                {
                    decl = decl->getNextSibling();
                    len += sprintf(this->_printbuff + len, "%s\n", decl->toString());
                }
            }
            Statement *stmt = this->_stmt;
            if ( !stmt->isNull() )
            {
                len += sprintf(this->_printbuff + len, "%s", stmt->toString());
                while ( stmt->hasNextSibling() )
                {
                    stmt = stmt->getNextSibling();
                    len += sprintf(this->_printbuff + len, "%s", stmt->toString());
                }
            }
            len += sprintf(this->_printbuff + len, "}\n");
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);
};

#endif

