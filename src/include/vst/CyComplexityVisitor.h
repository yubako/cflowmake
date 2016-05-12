#ifndef __CY_COMPLEXITY_VISITOR_H
#define __CY_COMPLEXITY_VISITOR_H

#include "vst/cyvisitor.h"
#include "pars/cytypes.h"
#include <string.h>
#include <stdio.h>
#include <vector>


class CyComplexityVisitor : public CyVisitor
{

    private:

        unsigned int _nodes;
        unsigned int _paths;

    public:
        CyComplexityVisitor()
        {
            this->_nodes = 0;
            this->_paths = 0;
        };
        virtual ~CyComplexityVisitor()
        {
        }


        /**
         * @override
         */
        virtual int visit(TranslationUnit* stmt);
        virtual int visit(NullStatement* stmt);
        virtual int visit(CompoundStatement* stmt);
        virtual int visit(DefaultStatement* stmt);
        virtual int visit(ExpressionStatement* stmt);
        virtual int visit(IfStatement* stmt);
        virtual int visit(WhileStatement* stmt);
        virtual int visit(ForStatement* stmt);
        virtual int visit(DoStatement* stmt);
        virtual int visit(GotoStatement* stmt);
        virtual int visit(LabeledStatement* stmt);
        virtual int visit(BreakStatement* stmt);
        virtual int visit(ContinueStatement* stmt);
        virtual int visit(ReturnStatement* stmt);
        virtual int visit(SwtStatement* stmt);
        virtual int visit(CaseStatement* stmt);
        virtual int visit(FunctionDefinition* decl);
};






#endif

