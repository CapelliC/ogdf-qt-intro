/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#include "mainwindow.h"
#include <QApplication>

#include <QSvgWidget>
#include <QSplitter>

#include "OgdfView.h"
#include "OrthogonalLayout.h"

#include "TestGraph.h"

#include <ogdf/planarity/PlanarizationLayout.h>
#include <ogdf/layered/SugiyamaLayout.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget *w = 0;
    auto a = app.arguments();

    if (a.size() == 2 && a[1] == "howto") {
        w = OrthogonalLayout();
    } else if (a.size() == 3 && a[1] == "dot") {

        GraphWithAttributes gwa;
        if (GraphIO::readDOT(gwa.a, gwa.g, a[2].toStdString())) {
            SugiyamaLayout layout;
            layout.call(gwa.a);
            std::stringstream st;
            //GraphIO::SVGSettings sett;
            //sett.curviness(.5);
            //sett.bezierInterpolation(true);
            if (GraphIO::drawSVG(gwa.a, st)) {
                auto svg = new QSvgWidget;
                svg->load(QByteArray(st.str().c_str()));
                w = svg;
            }
        }
    }
    else if (a.size() == 2 && a[1] == "cc") {
        auto m = new QMainWindow;
        auto s = new QSplitter(Qt::Horizontal);

        auto v = new OgdfView;
        s->addWidget(v);

        auto g = new QSvgWidget;
        s->addWidget(g);

        TestGraph tg;
        PlanarizationLayout layout;
        layout.call(tg.a);

        v->draw(tg);

        std::stringstream st;
        GraphIO::drawSVG(tg.a, st);
        g->load(QByteArray(st.str().c_str()));

        m->setCentralWidget(s);
        w = m;
    }
    else {
        w = new MainWindow;
    }

    if (w) {
        w->show();
        app.exec();
        delete w;
    }
}
