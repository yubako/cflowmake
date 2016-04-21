#ifndef CYTYPES_TRANSLATION_UNIT_H
#define CYTYPES_TRANSLATION_UNIT_H

class CyVisitor;
class TranslationUnit 
{
    private:
        static TranslationUnit* instance;
        TranslationUnit* _sibling;
        Declaration*     _decl;
        const char*      _src;
        char             _printbuff[4096];

        TranslationUnit(const char* src)
        {
            this->_decl    = NULL;
            this->_sibling = NULL;
            this->_src     = src;
        }

        void pushSibling(TranslationUnit* unit)
        {
            TranslationUnit* t = this;
            while ( t->_sibling )
            {
                t = t->_sibling;
            }
            t->_sibling = unit;
        }

    public:
        virtual ~TranslationUnit()
        {
        }

        static TranslationUnit* factory(const char* src)
        {
            TranslationUnit* unit = new TranslationUnit(src);
            if ( TranslationUnit::getInstance() )
            {
                TranslationUnit::getInstance()->pushSibling(unit);
            }
            else
            {
                TranslationUnit::instance = unit;
            }
            return unit;
        }

        static TranslationUnit* getInstance()
        {
            return TranslationUnit::instance;
        }

        void deleteInstance()
        {
            if ( TranslationUnit::instance )
                delete TranslationUnit::instance;
            TranslationUnit::instance = NULL;
        }

        Declaration* getDeclaration()
        {
            return this->_decl;
        }

        void pushDeclaration(Declaration* decl)
        {
            if ( this->_decl )
                this->_decl->pushSibling(decl);
            else
                this->_decl = decl;
        }

        const char* toString()
        {
            if ( this->getDeclaration() )
                sprintf(this->_printbuff, "%s", this->getDeclaration()->toString());
            return this->_printbuff;
        }

        const char* getSource()
        {
            return this->_src;
        }

        int accept(CyVisitor* visitor);
};

#endif
