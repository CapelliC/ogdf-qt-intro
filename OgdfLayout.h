/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef OGDFLAYOUT_H
#define OGDFLAYOUT_H

#include <QObject>
#include <QSettings>

#include <ogdf/basic/GraphAttributes.h>

class OgdfLayout : public QObject
{
    Q_OBJECT
public:
    explicit OgdfLayout(QObject *parent = 0);

    virtual void readSettings();
    virtual void writeSettings();
    virtual void readSettings(QSettings &) {}
    virtual void writeSettings(QSettings &) {}

    virtual void layout(ogdf::GraphAttributes &) = 0;

signals:

public slots:
};

#endif // OGDFLAYOUT_H
