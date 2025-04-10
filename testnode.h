// TestNode.h

#ifndef TESTNODE_H
#define TESTNODE_H

#include "BaseNode.h"

class TestNode : public BaseNode
{
public:
    TestNode();

    void process() override;
};

#endif // TESTNODE_H
