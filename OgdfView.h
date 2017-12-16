/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef OGDFVIEW_H
#define OGDFVIEW_H

#include <QGraphicsView>

#include "OgdfScene.h"
#include "GraphWithAttributes.h"

class OgdfView : public QGraphicsView
{
    Q_OBJECT
public:

    OgdfView(QWidget *parent = Q_NULLPTR);

    OgdfScene *scene() const { return qobject_cast<OgdfScene *>(QGraphicsView::scene()); }
    void draw(GraphWithAttributes &gwa);

private:

    OgdfSettings settings;
};

#endif // OGDFVIEW_H
