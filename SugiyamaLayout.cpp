/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "SugiyamaLayout.h"

SugiyamaLayout::SugiyamaLayout(QObject *p) : OgdfLayout(p) {

}
SugiyamaLayout::SugiyamaLayout(const SugiyamaLayout &) : OgdfLayout() {

}
SugiyamaLayout::~SugiyamaLayout() {

}
void SugiyamaLayout::layout(ogdf::GraphAttributes &GA) {
    ogdf::SugiyamaLayout::call(GA);
}

static int id_SugiyamaLayout = qRegisterMetaType<SugiyamaLayout>();
