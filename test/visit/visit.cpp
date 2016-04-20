
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"
#include "vst/cyvisitor.h"

#include "vst/CyFlowVisitor.h"


#include <stdio.h>

class FuncVisitor : public CyVisitor
{
    private:
        unsigned int _indent;

        void indent()
        {
            unsigned int i;
            for ( i = 0; i < this->_indent * 4; i++ ) 
            {
                printf(" ");
            }
        }

    public:

        FuncVisitor()
        {
            this->_indent = 0;
        }

        virtual int visit(FunctionDefinition* decl)
        {
            this->indent();
            printf("function name: %u:%s\n", decl->getLine(), decl->getName());
            this->_indent ++;

            return CyVisitor::VISIT_CONTINUE;
        }

        virtual int visit(CompoundStatement* stmt)
        {
            this->indent();
            printf("{\n");
            this->_indent ++;

            stmt->getStatement()->accept(this);

            this->_indent --;
            this->indent();
            printf("}\n");

            return CyVisitor::VISIT_CONTINUE;
        }

        virtual int visit(IfStatement* stmt)
        {
            this->indent();
            printf("ifStmt:%u:(%s)", stmt->getLine(), stmt->getExpression()->toString());
            stmt->getTrue()->accept(this);
            stmt->getElse()->accept(this);

            return CyVisitor::VISIT_CONTINUE;
        }

        virtual int visit(ExpressionStatement* stmt)
        {
            this->indent();
            printf("Expr:%u: %s\n", stmt->getLine(), stmt->toString());

            return CyVisitor::VISIT_CONTINUE;
        }

        virtual int visit(ReturnStatement* stmt)
        {
            this->indent();
            printf("Rtn:%u: Return\n", stmt->getLine());
            return CyVisitor::VISIT_CONTINUE;
        }
};

extern int yydebug;

TEST(visit, walkthrow)
{
    const char* path = "loadsrcs/func.c";
    FuncVisitor* visitor = new FuncVisitor();

    EXPECT_EQ( 0 ,cflowSrcParse(path));

    TranslationUnit* unit = TranslationUnit::getInstance();
    printf("hogehoge\n\n\n\n");
    unit->accept(visitor);
}


TEST(visit, flowVisitor)
{

    const char* path = "loadsrcs/func.c";
    CyFlowVisitor* visitor = new CyFlowVisitor();

    EXPECT_EQ( 0 ,cflowSrcParse(path));

    TranslationUnit* unit = TranslationUnit::getInstance();
    unit->accept(visitor);
    printf("hogehoge\n\n\n\n");
    visitor->save("graph.dot");
}

