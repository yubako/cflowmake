#ifndef CYTYPES_DECLARATION_H
#define CYTYPES_DECLARATION_H

#include "SourceLocation.h"
#include "Statement.h"


class Declaration : public SourceLocation
{

    private:
        Declaration *_sibling;

    public:
        Declaration(unsigned int line, const char* str)
            :SourceLocation(line, str)
        {
            this->_sibling = NULL;
        }

        virtual ~Declaration()
        {
        }

        Declaration* getNextSibling()
        {
            return this->_sibling;
        }

        int hasNextSibling()
        {
            if (this->_sibling)
                return 1;
            return 0;
        }

        void pushSibling(Declaration* decl)
        {
            Declaration* sibling = this;
            while ( sibling->hasNextSibling() )
            {
                sibling = sibling->getNextSibling();
            }
            sibling->_sibling = decl;
        }

        const char* toString()
        {
            unsigned int len = 0;

            len += sprintf(this->_printbuff + len, "%s", this->getCodeString());
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

class FunctionDefinition : public Declaration
{
    private:
        const char* _funcname;
        Statement*  _stmt;

    public:
        FunctionDefinition(unsigned int line, const char* funcname, Statement* stmt)
            : Declaration(line, "function")
        {
            this->_funcname = funcname;
            this->_stmt = stmt;
        }
        virtual ~FunctionDefinition()
        {
        }

        Statement* getStatement()
        {
            return this->_stmt;
        }

        const char* getName()
        {
            return this->_funcname;
        }

        const char* toString()
        {
            sprintf(this->_printbuff, "%s", this->getName());
            return this->_printbuff;
        }

        /**
         * @override
         */
        virtual int accept(CyVisitor* visitor);
};


class NullDeclaration : public Declaration
{
    public:
        NullDeclaration() 
            : Declaration(0, "Null")
        {
        }

        virtual ~NullDeclaration()
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

