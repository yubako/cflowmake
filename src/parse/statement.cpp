#include "cytypes.h"
#include "cyvisitor.h"

void NullStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void CompoundStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void DefaultStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void ExpressionStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void IfStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void WhileStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void ForStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void DoStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void GotoStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void LabeledStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void BreakStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void ContinueStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void ReturnStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void SwtStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}

void CaseStatement::accept(CyVisitor* visitor)
{
    visitor->visit(this);
    if ( this->hasNextSibling() )
        this->getNextSibling()->accept(visitor);
}


