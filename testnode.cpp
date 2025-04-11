// testnode.cpp
#include "testnode.h"

TestNode::TestNode() : BaseNode("Test Node")
{
    addInputPort("In");
    addOutputPort("Out");
}

void TestNode::process()
{
    // Example logic (empty for now)
}
