#-------------------------------------------------
#
# Project created by QtCreator 2017-12-16T17:45:11
#
#-------------------------------------------------

QT += core gui svg widgets svgwidgets

TARGET = basic_sample
TEMPLATE = app

# note: OGDF must be precompiled, here is the path of source folder

#OGDF = C:/dev/ogdf
OGDF = ../../ogdf
INCLUDEPATH += $$OGDF/include

CONFIG(debug, debug|release) {
  OGDF_BUILD = $$OGDF/build/debug/Debug
} else {
  OGDF_BUILD = $$OGDF/build/release
  DEFINES += NDEBUG
}

INCLUDEPATH += $$OGDF_BUILD/include

#LIBPATH += $$OGDF_BUILD
LIBS += -L$$OGDF_BUILD -lOGDF -lCOIN

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# get the ogdf-qt-intro includes
INCLUDEPATH += ..

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ../OgdfScene.cpp \
    ../RadialTreeLayout.cpp \
    ../SugiyamaLayout.cpp \
    ../OgdfLayouts.cpp \
    ../OgdfLayout.cpp \
    ../OgdfView.cpp \
    ../GraphWithAttributes.cpp \
    ../OgdfSettings.cpp \
    TestGraph.cpp \
    ogdfwidget.cpp

HEADERS += \
    mainwindow.h \
    ../RadialTreeLayout.h \
    ../SugiyamaLayout.h \
    ../OgdfLayout.h \
    ../OgdfLayouts.h \
    ../OgdfView.h \
    ../OgdfScene.h \
    ../GraphWithAttributes.h \
    ../OgdfSettings.h \
    TestGraph.h \
    ogdfwidget.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    Screenshot.png \
    ../README.md
