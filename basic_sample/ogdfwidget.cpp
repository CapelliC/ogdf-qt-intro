/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#include "ogdfwidget.h"

OgdfWidget::OgdfWidget(QWidget *parent) : OgdfView(parent)
{

}

node OgdfWidget::addNode(const QSize& size)
{
    node newNode = gwa.g.newNode();

    gwa.a.width(newNode) = size.width();
    gwa.a.height(newNode) = size.height();

    return newNode;
}

void OgdfWidget::addEdge(const ogdf::node& source, const ogdf::node& target)
{
    gwa.g.newEdge(source, target);
}
