#ifndef CYTYPES_VISITOR_H
#define CYTYPES_VISITOR_H

#include "cytypes.h"

class CyVisitor
{
    public:

        virtual void visit(TranslationUnit* stmt){}

        /* statement */
        virtual void visit(NullStatement* stmt){}
        virtual void visit(CompoundStatement* stmt){}
        virtual void visit(DefaultStatement* stmt){}
        virtual void visit(ExpressionStatement* stmt){}
        virtual void visit(IfStatement* stmt){}
        virtual void visit(WhileStatement* stmt){}
        virtual void visit(ForStatement* stmt){}
        virtual void visit(DoStatement* stmt){}
        virtual void visit(GotoStatement* stmt){}
        virtual void visit(LabeledStatement* stmt){}
        virtual void visit(BreakStatement* stmt){}
        virtual void visit(ContinueStatement* stmt){}
        virtual void visit(ReturnStatement* stmt){}
        virtual void visit(SwtStatement* stmt){}
        virtual void visit(CaseStatement* stmt){}

        /* declaration */
        virtual void visit(Declaration* decl){}
        virtual void visit(FunctionDefinition* decl){}
        virtual void visit(NullDeclaration* decl){}
        
        /* expression */
        virtual void visit(Expression* expr){}
        virtual void visit(NullExpression* expr){}
};


#endif
