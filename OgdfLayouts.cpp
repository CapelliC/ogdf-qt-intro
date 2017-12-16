/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "OgdfLayouts.h"
#include "OgdfLayout.h"

#include <QMenuBar>
#include <QMetaObject>

#include <ogdf/layered/SugiyamaLayout.h>
//#include <ogdf/energybased/PivotMDS.h>
//#include <ogdf/energybased/SpringEmbedderGridVariant.h>
//#include <ogdf/energybased/GEMLayout.h>
//#include <ogdf/energybased/MultilevelLayout.h>
//#include <ogdf/energybased/TutteLayout.h>
//#include <ogdf/energybased/multilevelmixer/MixedForceLayout.h>
//#include <ogdf/energybased/multilevelmixer/ModularMultilevelMixer.h>
//#include <ogdf/energybased/multilevelmixer/MMMExampleFastLayout.h>
//#include <ogdf/energybased/multilevelmixer/MMMExampleNiceLayout.h>
//#include <ogdf/energybased/multilevelmixer/MMMExampleNoTwistLayout.h>
//#include <ogdf/energybased/StressMinimization.h>
//#include <ogdf/energybased/FMMMLayout.h>
//#include <ogdf/energybased/DavidsonHarelLayout.h>
//#include <ogdf/energybased/SpringEmbedderKK.h>
//#include <ogdf/internal/energybased/DTreeMultilevelEmbedder.h>
//#include <ogdf/tree/RadialTreeLayout.h>
//#include <ogdf/tree/TreeLayout.h>
//#include <ogdf/module/ForceLayoutModule.h>
//#include <ogdf/module/MultilevelLayoutModule.h>
//#include <ogdf/module/GridLayoutModule.h>
//#include <ogdf/packing/ComponentSplitterLayout.h>
//#include <ogdf/packing/SimpleCCPacker.h>
//#include <ogdf/planarity/PlanarizationLayout.h>
//#include <ogdf/misclayout/BertaultLayout.h>
//#include <ogdf/misclayout/CircularLayout.h>
//#include <ogdf/misclayout/LinearLayout.h>
//#include <ogdf/misclayout/ProcrustesSubLayout.h>
//#include <ogdf/misclayout/BalloonLayout.h>
//#include <ogdf/upward/DominanceLayout.h>
//#include <ogdf/upward/VisibilityLayout.h>
//#include <ogdf/upward/UpwardPlanarizationLayout.h>
/*
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

    SugiyamaLayout(QObject *p = 0) : OgdfLayout(p) {}
    SugiyamaLayout(const SugiyamaLayout &src) : OgdfLayout() {}
    ~SugiyamaLayout() {}

    Q_INVOKABLE virtual void layout(ogdf::GraphAttributes &GA) override {
        ogdf::SugiyamaLayout::call(GA);
    }
};
*/

void OgdfLayouts::addLayouts(QMainWindow *w) {
    auto m = w->menuBar()->addMenu("Layouts");
    for (auto x :
        {"SugiyamaLayout"
//        "PivotMDS",
//        "SpringEmbedderGridVariant",
//        "GEMLayout",
//        "MultilevelLayout",
//        "TutteLayout",
//        "MixedForceLayout",
//        "ModularMultilevelMixer",
//        "MMMExampleFastLayout",
//        "MMMExampleNiceLayout",
//        "MMMExampleNoTwistLayout",
//        "StressMinimization",
//        "FastMultipoleEmbedder",
//        "FastMultipoleMultilevelEmbedder",
//        "FMMMLayout",
//        "DavidsonHarelLayout",
//        "SpringEmbedderKK",
//        "DTreeMultilevelEmbedder2D",
//        "DTreeMultilevelEmbedder3D",
//        "RadialTreeLayout",
//        "TreeLayout",
//        "ForceLayoutModule",
//        "MultilevelLayoutModule",
//        "GridLayoutModule",
//        "ComponentSplitterLayout",
//        "PlanarizationLayout",
//        "BertaultLayout",
//        "CircularLayout",
//        "LinearLayout",
//        "ProcrustesSubLayout",
//        "BalloonLayout",
//        "DominanceLayout",
//        "VisibilityLayout",
//        "UpwardPlanarizationLayout"
    })
        m->addAction(x);
}

OgdfLayouts::OgdfLayouts(QObject *parent) : QObject(parent) {

}
