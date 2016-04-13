#include "cytypes.h"
#include "cyvisitor.h"

TranslationUnit *TranslationUnit::instance = NULL;

void TranslationUnit::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    this->getDeclaration()->accept(visitor);
}


