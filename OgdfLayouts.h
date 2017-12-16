/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef OGDFLAYOUTS_H
#define OGDFLAYOUTS_H

#include <QMainWindow>

class OgdfLayouts : public QObject
{
    Q_OBJECT

public:

    explicit OgdfLayouts(QObject *parent = 0);
    void addLayouts(QMainWindow *w);

signals:

public slots:
};

#endif // OGDFLAYOUTS_H
