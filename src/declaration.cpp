#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

int Declaration::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;;
    if( visitor->visit(this) == CyVisitor::VISIT_BREAK)
        return CyVisitor::VISIT_BREAK;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}

int FunctionDefinition::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;;
    if( visitor->visit(this) == CyVisitor::VISIT_BREAK)
        return CyVisitor::VISIT_BREAK;

    this->getStatement()->accept(visitor);
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int NullDeclaration::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;;
    if( visitor->visit(this) == CyVisitor::VISIT_BREAK)
        return CyVisitor::VISIT_BREAK;

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    visitor->leave(this);
    return ope;
}

