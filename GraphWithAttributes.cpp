/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "GraphWithAttributes.h"

GraphWithAttributes::GraphWithAttributes()
    : a(g   , GraphAttributes::nodeGraphics
            | GraphAttributes::nodeType
            | GraphAttributes::nodeLabel
            | GraphAttributes::nodeStyle
            | GraphAttributes::edgeGraphics
            | GraphAttributes::edgeType
            | GraphAttributes::edgeArrow)
{

}
