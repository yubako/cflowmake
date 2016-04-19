
#include <stdio.h>
#include "vst/CyFlowVisitor.h"

using namespace std;


void CyFlowDotGraph::saveDotFile(FILE* fp)
{
    char buffer[4096];
    unsigned int len = 0;
    std::vector<CyFlowDotEdge*>::iterator it;

    len += sprintf(buffer + len, "\nsubgraph \"cluster_%s\" {\n", this->_name);
    len += sprintf(buffer + len, "label = \"%s\";\n", this->_name);

    for ( it = this->_edges.begin(); it != this->_edges.end(); it++)
    {
        CyFlowDotEdge* edge = *it;
        len += sprintf(buffer + len, "%s", edge->toString());
    }

    len += sprintf(buffer + len, "}\n ");

    printf("%s\n", buffer);
}


