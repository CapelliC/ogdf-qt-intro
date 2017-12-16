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

    Q_PROPERTY(int fails READ fails WRITE fails)
    Q_PROPERTY(int runs READ runs WRITE runs)
    Q_PROPERTY(bool transpose READ transpose WRITE transpose)
    Q_PROPERTY(bool arrangeCCs READ arrangeCCs WRITE arrangeCCs)
    Q_PROPERTY(double minDistCC READ minDistCC WRITE minDistCC)
    Q_PROPERTY(double pageRatio READ pageRatio WRITE pageRatio)
    Q_PROPERTY(bool alignBaseClasses READ alignBaseClasses WRITE alignBaseClasses)
    Q_PROPERTY(bool alignSiblings READ alignSiblings WRITE alignSiblings)
    //void setSubgraphs
    Q_PROPERTY(bool permuteFirst READ permuteFirst WRITE permuteFirst)
    Q_PROPERTY(uint maxThreads READ maxThreads WRITE maxThreads)

public:

    SugiyamaLayout(QObject *p = 0);
    SugiyamaLayout(const SugiyamaLayout &src);
    ~SugiyamaLayout();

    Q_INVOKABLE virtual void layout(ogdf::GraphAttributes &GA) override;
};

Q_DECLARE_METATYPE(SugiyamaLayout)

#endif // SUGIYAMALAYOUT_H
