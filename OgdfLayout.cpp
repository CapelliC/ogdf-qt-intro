/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "OgdfLayout.h"

OgdfLayout::OgdfLayout(QObject *parent) : QObject(parent) {

}

void OgdfLayout::readSettings() {
    QSettings settings;
    settings.beginGroup(metaObject()->className());
    readSettings(settings);
    settings.endGroup();
}

void OgdfLayout::writeSettings() {
    QSettings settings;
    settings.beginGroup(metaObject()->className());
    writeSettings(settings);
    settings.endGroup();
}
