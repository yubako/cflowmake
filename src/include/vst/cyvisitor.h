#ifndef CYTYPES_VISITOR_H
#define CYTYPES_VISITOR_H

#include "pars/cytypes.h"

class CyVisitor
{
    public:

        static const int VISIT_CONTINUE = 1;
        static const int VISIT_BREAK    = 2;
        static const int VISIT_RETURN   = 3;

        virtual int visit(TranslationUnit* stmt){return CyVisitor::VISIT_CONTINUE;}

        /* statement */
        virtual int visit(NullStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(CompoundStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(DefaultStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(ExpressionStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(IfStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(WhileStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(ForStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(DoStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(GotoStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(LabeledStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(BreakStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(ContinueStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(ReturnStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(SwtStatement* stmt){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(CaseStatement* stmt){return CyVisitor::VISIT_CONTINUE;}

        /* declaration */
        virtual int visit(FunctionDefinition* decl){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(Declaration* decl){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(NullDeclaration* decl){return CyVisitor::VISIT_CONTINUE;}

        /* expression */
        virtual int visit(Expression* expr){return CyVisitor::VISIT_CONTINUE;}
        virtual int visit(NullExpression* expr){return CyVisitor::VISIT_CONTINUE;}

};


#endif
