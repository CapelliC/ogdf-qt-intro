/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef GRAPHWITHATTRIBUTES_H
#define GRAPHWITHATTRIBUTES_H

#include <ogdf/basic/GraphAttributes.h>
using namespace ogdf;

class GraphWithAttributes
{
public:
    GraphWithAttributes();

    Graph g;
    GraphAttributes a;
};

#endif // GRAPHWITHATTRIBUTES_H
