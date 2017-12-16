/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#include "TestGraph.h"

TestGraph::TestGraph(Color fillColor,
                     std::function<std::string(node)> label,
                     double AllWidth, double AllHeight)
{
    auto nd = [&]() {
        auto n = g.newNode();
        a.label(n) = label(n); //'N' + std::to_string(n->index());
        a.fillColor(n) = fillColor;
        return n;
    };

    node ns[] = { nd(), nd(), nd(), nd(), nd(), nd() };
    g.newEdge(ns[0], ns[2]);
    g.newEdge(ns[2], ns[3]);
    g.newEdge(ns[2], ns[1]);
    g.newEdge(ns[1], ns[3]);
    g.newEdge(ns[0], ns[1]);
    g.newEdge(ns[0], ns[3]);
    g.newEdge(ns[0], ns[5]);
    g.newEdge(ns[4], ns[5]);
    g.newEdge(ns[1], ns[4]);

    a.setAllWidth(AllWidth);
    a.setAllHeight(AllHeight);
}
