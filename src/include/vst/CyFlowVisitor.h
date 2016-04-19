#ifndef CYTYPES_FLOW_VISITOR
#define CYTYPES_FLOW_VISITOR

#include "vst/cyvisitor.h"
#include "pars/cytypes.h"
#include "CyFlowDotNode.h"
#include "CyFlowDotEdge.h"
#include "CyFlowDotGraph.h"
#include <string.h>
#include <stdio.h>
#include <vector>

class CyFlowVisitor : public CyVisitor 
{
    private:
        std::vector<CyFlowDotGraph*>    _graphs;
        CyFlowDotGraph*                 _graph;
        const char*                     _src;

    public:
        CyFlowVisitor() { }
        virtual ~CyFlowVisitor() { }

        void save(const char* fpath);

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
        virtual void leave(FunctionDefinition* decl);

};

#endif

