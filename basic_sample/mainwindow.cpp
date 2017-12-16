/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui_.setupUi(this);

    auto &v = *ui_.widget;
    auto nd = [&]() { return v.addNode(QSize(60, 50)); };
    ogdf::node ns[] = { nd(), nd(), nd(), nd(), nd(), nd() };
    v.addEdge(ns[0], ns[2]);
    v.addEdge(ns[2], ns[3]);
    v.addEdge(ns[2], ns[1]);
    v.addEdge(ns[1], ns[3]);
    v.addEdge(ns[0], ns[1]);
    v.addEdge(ns[0], ns[3]);
    v.addEdge(ns[0], ns[5]);
    v.addEdge(ns[4], ns[5]);
    v.addEdge(ns[1], ns[4]);
    v.layout();
}

MainWindow::~MainWindow()
{

}
