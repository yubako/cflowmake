#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

int Expression::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}

int NullExpression::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}


