#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

TranslationUnit *TranslationUnit::instance = NULL;

int TranslationUnit::accept(CyVisitor* visitor)
{
    int ope;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;

    if ( this->getDeclaration() )
        ope = this->getDeclaration()->accept(visitor);

    visitor->leave(this);
    return ope;
}


