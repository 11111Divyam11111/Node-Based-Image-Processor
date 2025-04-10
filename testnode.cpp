// TestNode.cpp

#include "TestNode.h"
#include <QDebug>

TestNode::TestNode()
    : BaseNode("Test Node")
{
}

void TestNode::process()
{
    qDebug() << "TestNode is being processed.";
}
