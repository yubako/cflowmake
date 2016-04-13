#include "cytypes.h"
#include "cyvisitor.h"

void Expression::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void NullExpression::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

