/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#include "OrthogonalLayout.h"

#include <ogdf/planarity/PlanarizationLayout.h>
#include <ogdf/planarity/SubgraphPlanarizer.h>
#include <ogdf/planarity/VariableEmbeddingInserter.h>
#include <ogdf/planarity/FastPlanarSubgraph.h>
#include <ogdf/orthogonal/OrthoLayout.h>
#include <ogdf/planarity/EmbedderMinDepthMaxFaceLayers.h>
#include <ogdf/fileformats/GraphIO.h>


using namespace ogdf;

QSvgWidget *OrthogonalLayout()
{
    Graph G;
    GraphAttributes GA(G,
                       GraphAttributes::nodeGraphics |
                       GraphAttributes::edgeGraphics |
                       GraphAttributes::nodeLabel |
                       GraphAttributes::edgeStyle | GraphAttributes::edgeType |
                       GraphAttributes::nodeStyle | GraphAttributes::nodeType |
                       GraphAttributes::nodeTemplate);
    GraphIO::readGML(GA, G, "/home/carlo/Downloads/er-diagram.gml");

    PlanarizationLayout pl;

    SubgraphPlanarizer *crossMin = new SubgraphPlanarizer;

    FastPlanarSubgraph *ps = new FastPlanarSubgraph;
    ps->runs(100);
    VariableEmbeddingInserter *ves = new VariableEmbeddingInserter;
    ves->removeReinsert(rrAll);

    crossMin->setSubgraph(ps);
    crossMin->setInserter(ves);

    EmbedderMinDepthMaxFaceLayers *emb = new EmbedderMinDepthMaxFaceLayers;
    pl.setEmbedder(emb);

    OrthoLayout *ol = new OrthoLayout;
    ol->separation(20.0);
    ol->cOverhang(0.4);
    pl.setPlanarLayouter(ol);

    pl.call(GA);

    //GraphIO::writeGML(GA, "ERDiagram-layout.gml");
    std::stringstream st;
    if (GraphIO::drawSVG(GA, st)) {
        auto svg = new QSvgWidget;
        svg->load(QByteArray(st.str().c_str()));
        return svg;
    }

    return 0;
}
