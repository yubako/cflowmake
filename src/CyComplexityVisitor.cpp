
#include "vst/CyComplexityVisitor.h"

/* Node : 文、式、制御合流点 */
/* Path : 有向辺             */
 

int CyComplexityVisitor::visit(TranslationUnit* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}
int CyComplexityVisitor::visit(FunctionDefinition* decl)
{
    this->_nodes = 0;
    this->_paths = 0;

    decl->getStatement()->accept(this);

    printf("%s: Node = %u, Path = %u, Complexity = %u\n", 
            decl->toString(), this->_nodes, this->_paths, (this->_paths - this->_nodes) + 2);

    return CyVisitor::VISIT_CONTINUE;
}
int CyComplexityVisitor::visit(NullStatement* stmt)
{
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(CompoundStatement* stmt)
{
    return stmt->getStatement()->accept(this);
}

int CyComplexityVisitor::visit(ExpressionStatement* stmt)
{
    this->_paths ++;
    this->_nodes ++;
    return CyVisitor::VISIT_CONTINUE;
}
int CyComplexityVisitor::visit(IfStatement* stmt)
{
    this->_paths ++;
    this->_nodes ++;

    stmt->getTrue()->accept(this);
    stmt->getElse()->accept(this);
    
    /* 合流地点 */
    this->_paths += 2;
    this->_nodes ++;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(WhileStatement* stmt)
{
    this->_nodes ++;
    this->_paths += 2;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(ForStatement* stmt)
{
    this->_nodes ++;
    this->_paths += 2;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(DoStatement* stmt)
{
    this->_nodes ++;
    this->_paths += 2;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(GotoStatement* stmt)
{
    this->_nodes ++;
    this->_paths ++;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(LabeledStatement* stmt)
{
    this->_nodes ++;
    this->_paths ++;
    return CyVisitor::VISIT_CONTINUE;
}
int CyComplexityVisitor::visit(BreakStatement* stmt)
{
    this->_nodes ++;
    this->_paths += 2;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(ContinueStatement* stmt)
{
    this->_nodes ++;
    this->_paths += 2;
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(ReturnStatement* stmt)
{
    this->_nodes ++;
    this->_paths ++;
    return CyVisitor::VISIT_RETURN;
}

int CyComplexityVisitor::visit(SwtStatement* stmt)
{
    this->_nodes ++;
    this->_paths ++;
    stmt->getStatement()->accept(this);
    return CyVisitor::VISIT_CONTINUE;

}

int CyComplexityVisitor::visit(DefaultStatement* stmt)
{
    this->_nodes ++;
    this->_paths +=2; /* 合流地点も込み */
    return CyVisitor::VISIT_CONTINUE;
}

int CyComplexityVisitor::visit(CaseStatement* stmt)
{
    this->_nodes ++;
    this->_paths +=2; /* 合流地点も込み */
    return CyVisitor::VISIT_CONTINUE;
}



