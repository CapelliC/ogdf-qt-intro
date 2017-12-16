/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "RadialTreeLayout.h"

RadialTreeLayout::RadialTreeLayout(QObject *p) : OgdfLayout(p) {

}
RadialTreeLayout::RadialTreeLayout(const RadialTreeLayout &) : OgdfLayout(), ogdf::RadialTreeLayout() {

}
RadialTreeLayout::~RadialTreeLayout() {

}

void RadialTreeLayout::layout(ogdf::GraphAttributes &GA) {
    ogdf::RadialTreeLayout::call(GA);
}

static int id_RadialTreeLayout = qRegisterMetaType<RadialTreeLayout>();
