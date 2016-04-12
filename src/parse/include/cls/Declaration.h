#ifndef CYTYPES_DECLARATION_H
#define CYTYPES_DECLARATION_H

#include "SourceLocation.h"


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
};

#endif

