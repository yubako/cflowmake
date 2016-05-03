#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

int Expression::accept(CyVisitor* visitor)
{
    int ope;
    ope = visitor->visit(this);
    if ( ope != CyVisitor::VISIT_CONTINUE )
        return ope;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int NullExpression::accept(CyVisitor* visitor)
{
    int ope;
    ope =visitor->visit(this);
    if ( ope != CyVisitor::VISIT_CONTINUE )
        return ope;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}


