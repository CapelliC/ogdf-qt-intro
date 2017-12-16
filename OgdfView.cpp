/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "OgdfView.h"
#include <ogdf/planarity/PlanarizationLayout.h>

OgdfView::OgdfView(QWidget *parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setRenderHint(QPainter::TextAntialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
}

void OgdfView::draw(GraphWithAttributes &gwa)
{
    setScene(new OgdfScene(gwa.a, settings));
    scene()->draw();
}
