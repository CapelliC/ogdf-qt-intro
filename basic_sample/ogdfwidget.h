/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#ifndef OGDFWIDGET_H
#define OGDFWIDGET_H

#include <QWidget>
#include "OgdfView.h"

class OgdfWidget : public OgdfView
{
    Q_OBJECT
public:
    explicit OgdfWidget(QWidget *parent = nullptr);

    ogdf::node addNode(const QSize& size);
    void addEdge(const ogdf::node& source, const ogdf::node& target);

signals:

public slots:

private:
    GraphWithAttributes gwa;
};

#endif // OGDFWIDGET_H
