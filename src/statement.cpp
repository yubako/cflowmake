#include "pars/cytypes.h"
#include "vst/cyvisitor.h"

int NullStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int CompoundStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int DefaultStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int ExpressionStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int IfStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int WhileStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int ForStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int DoStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int GotoStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int LabeledStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int BreakStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int ContinueStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int ReturnStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int SwtStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}

int CaseStatement::accept(CyVisitor* visitor)
{
    int ope = CyVisitor::VISIT_CONTINUE;
    if ( visitor->visit(this) == CyVisitor::VISIT_BREAK )
        return CyVisitor::VISIT_BREAK;
    visitor->leave(this);

    if ( this->hasNextSibling() )
        ope = this->getNextSibling()->accept(visitor);

    return ope;
}


