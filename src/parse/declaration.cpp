#include "cytypes.h"
#include "cyvisitor.h"

void Declaration::accept(CyVisitor* visitor)
{
    visitor->visit(this);

    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void FunctionDefinition::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    this->getStatement()->accept(visitor);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void NullDeclaration::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

