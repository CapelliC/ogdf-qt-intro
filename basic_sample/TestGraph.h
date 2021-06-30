/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include "GraphWithAttributes.h"
#include <functional>

class TestGraph : public GraphWithAttributes
{
public:

    TestGraph(Color fillColor = Color::Name::Green,
              std::function<std::string(node)> label = [](node n) { return 'N' + std::to_string(n->index()); },
              double AllWidth = 60, double AllHeight = 50);
};

#endif // TESTGRAPH_H
