
#include <stdio.h>
#include "vst/CyFlowVisitor.h"

FILE* graph_file_open(const char* fpath, const char* name)
{
    char fname[256];
    unsigned int len, i;
    len = sprintf(fname, "%s_%s.dot", fpath, name);

    for ( i = 0; i < len; i++ ) 
    {
        if ( fname[i] == ' ')
        {
            fname[i] ='_';
        }
    }
    FILE* fp = fopen(fname, "w");
    if ( fp == NULL ) 
    {
        fprintf(stderr, "cannot open file %s\n", fname);
    }
    return fp;
}

void CyFlowDotGraph::saveDotFile(const char* fpath)
{
    char* buffer = new char[1024 * 1024];
    unsigned int len = 0;
    FILE* fp = graph_file_open(fpath, this->_name);
    if ( fp == NULL ) return;

    std::vector<CyFlowPath*>::iterator it;

    len += sprintf(buffer + len, "digraph \"%s\" {\n\n", this->_name);
    len += sprintf(buffer + len, "    label = \"%s\";\n", this->_name);
    fprintf(fp, buffer);
    len = 0;

    len += CyFlowDotEdge::edgeDefaultDefine(buffer + len);
    len += CyFlowDotNode::nodeDefaultDefine(buffer + len);
    fprintf(fp, buffer);
    len = 0;

    for ( it = this->_paths.begin(); it != this->_paths.end(); it++)
    {
        CyFlowPath* path = *it;
        len += path->save(buffer + len);

        fprintf(fp, buffer);
        len = 0;
    }

    len += sprintf(buffer + len, "}\n ");
    fprintf(fp, buffer);

    fclose(fp);
}

