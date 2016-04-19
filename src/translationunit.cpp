#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

TranslationUnit *TranslationUnit::instance = NULL;

int TranslationUnit::accept(CyVisitor* visitor)
{
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;

    int ope = this->getDeclaration()->accept(visitor);
    visitor->leave(this);
    return ope;
}


