
#include <stdio.h>
#include "vst/CyFlowVisitor.h"

using namespace std;


void CyFlowDotGraph::saveDotFile(FILE* fp)
{
    char buffer[4096];
    unsigned int len = 0;
    std::vector<CyFlowPath*>::iterator it;

    len += sprintf(buffer + len, "digraph \"%s\" {\n\n", this->_name);
    len += sprintf(buffer + len, "    label = \"%s\";\n", this->_name);
    len += CyFlowDotEdge::edgeDefaultDefine(buffer + len);
    len += CyFlowDotNode::nodeDefaultDefine(buffer + len);

    for ( it = this->_paths.begin(); it != this->_paths.end(); it++)
    {
        CyFlowPath* path = *it;
        len += path->save(buffer + len);
    }

    len += sprintf(buffer + len, "}\n ");

    fprintf(fp, buffer);
}

