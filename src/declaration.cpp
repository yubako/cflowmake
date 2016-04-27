#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

int Declaration::accept(CyVisitor* visitor)
{
    int ope;
    ope = visitor->visit(this);
    if ( ope != CyVisitor::VISIT_CONTINUE )
        return ope;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}

int FunctionDefinition::accept(CyVisitor* visitor)
{
    int ope;
    ope = visitor->visit(this); 
    if ( ope != CyVisitor::VISIT_CONTINUE )
        return ope;

    this->getStatement()->accept(visitor);
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int NullDeclaration::accept(CyVisitor* visitor)
{
    int ope;
    ope =visitor->visit(this);
    if ( ope != CyVisitor::VISIT_CONTINUE )
        return ope;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}

