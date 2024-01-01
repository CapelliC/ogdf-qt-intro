/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef RADIALTREELAYOUT_H
#define RADIALTREELAYOUT_H

#include "OgdfLayout.h"
#include <ogdf/tree/RadialTreeLayout.h>

class RadialTreeLayout : public OgdfLayout, public ogdf::RadialTreeLayout {
    Q_OBJECT

    Q_PROPERTY(double levelDistance READ levelDistance WRITE levelDistance CONSTANT)
    //Q_PROPERTY(double connectedComponentDistance READ connectedComponentDistance WRITE connectedComponentDistance)

    Q_ENUM(RootSelectionType)
    Q_PROPERTY(RootSelectionType rootSelection READ rootSelection WRITE rootSelection CONSTANT)

public:

    RadialTreeLayout(QObject *p = 0);
    RadialTreeLayout(const RadialTreeLayout &src);
    ~RadialTreeLayout();

    Q_INVOKABLE virtual void layout(ogdf::GraphAttributes &GA) override;

signals:

public slots:
};

Q_DECLARE_METATYPE(RadialTreeLayout)

#endif // RADIALTREELAYOUT_H
