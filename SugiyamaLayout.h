/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef SUGIYAMALAYOUT_H
#define SUGIYAMALAYOUT_H

#include "OgdfLayout.h"
#include <ogdf/layered/SugiyamaLayout.h>

class SugiyamaLayout : public OgdfLayout, public ogdf::SugiyamaLayout {
    Q_OBJECT

    Q_PROPERTY(int fails READ fails CONSTANT)
    Q_PROPERTY(int runs READ runs CONSTANT)
    Q_PROPERTY(bool transpose READ transpose CONSTANT)
    Q_PROPERTY(bool arrangeCCs READ arrangeCCs CONSTANT)
    Q_PROPERTY(double minDistCC READ minDistCC CONSTANT)
    Q_PROPERTY(double pageRatio READ pageRatio CONSTANT)
    Q_PROPERTY(bool alignBaseClasses READ alignBaseClasses CONSTANT)
    Q_PROPERTY(bool alignSiblings READ alignSiblings CONSTANT)
    //void setSubgraphs
    Q_PROPERTY(bool permuteFirst READ permuteFirst CONSTANT)
    Q_PROPERTY(uint maxThreads READ maxThreads CONSTANT)

public:

    SugiyamaLayout(QObject *p = 0);
    SugiyamaLayout(const SugiyamaLayout &src);
    ~SugiyamaLayout();

    Q_INVOKABLE virtual void layout(ogdf::GraphAttributes &GA) override;
};

Q_DECLARE_METATYPE(SugiyamaLayout)

#endif // SUGIYAMALAYOUT_H
