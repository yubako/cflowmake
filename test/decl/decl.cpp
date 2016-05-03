
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"
#include "vst/cyvisitor.h"

#include "vst/CyFlowVisitor.h"


#include <stdio.h>

TEST(visit, declTest)
{
    const char* path = "loadsrcs/decl.c";
    CyFlowVisitor* visitor = new CyFlowVisitor();

    EXPECT_EQ( 0 ,cflowSrcParse(path));

    TranslationUnit* unit = TranslationUnit::getInstance();
    unit->accept(visitor);
    visitor->save("dots/decl");
    unit->deleteInstance();
    delete visitor;
}
