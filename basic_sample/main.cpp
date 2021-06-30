/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#include "mainwindow.h"
#include <QApplication>

#include <QSvgWidget>
#include <QSplitter>

#include "OgdfView.h"
#include "TestGraph.h"

#include <ogdf/planarity/PlanarizationLayout.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget *w = nullptr;

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

    if (w) {
        w->show();
        app.exec();
        delete w;
    }
}
