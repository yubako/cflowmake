#ifndef CYTYPES_FLOW_VISITOR
#define CYTYPES_FLOW_VISITOR

#include "vst/cyvisitor.h"
#include "pars/cytypes.h"
#include "CyFlowDotNode.h"
#include "CyFlowDotEdge.h"
#include "CyFlowDotGraph.h"
#include "vst/CyFlowLoopColor.h"
#include <string.h>
#include <stdio.h>
#include <vector>


class CyFlowBlock
{
    private:
        CyFlowDotNode       *_begin;
        CyFlowDotNode       *_end;
        unsigned int         _type;

    public:

        static int TYPE_LOOP;
        static int TYPE_SWITCH;

        CyFlowBlock(unsigned int type, CyFlowDotNode* begin, CyFlowDotNode* end)
        {
            this->_begin = begin;
            this->_end   = end;
            this->_type  = type;
        }
        virtual ~CyFlowBlock()
        {
        }

        CyFlowDotNode *begin()
        {
            return this->_begin;
        }

        CyFlowDotNode *end()
        {
            return this->_end;
        }

        int getType()
        {
            return this->_type;
        }
};

class CyFlowVisitor : public CyVisitor 
{
    private:
        std::vector<CyFlowBlock>        _its;
        std::vector<CyFlowDotGraph*>    _graphs;
        CyFlowDotGraph                 *_graph;
        CyFlowPath                     *_path;
        const char                     *_src;
        CyFlowLoopColor                *_color;

        CyFlowPath* pathSwitch(CyFlowPath* path)
        {
            CyFlowPath* path_old = this->_path;
            this->_path = path;
            return path_old;
        }

    public:
        CyFlowVisitor() 
        {
            this->_color = new CyFlowLoopColor();
        }
        virtual ~CyFlowVisitor() 
        { 
            delete this->_color;
        }

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

};

#endif

