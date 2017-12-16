/*
 * ogdf-qt-intro/basic_sample
 * @ CapelliC 2017
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui_MainWindow ui_;
};

#endif // MAINWINDOW_H
