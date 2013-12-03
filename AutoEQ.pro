#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T19:57:26
#
#-------------------------------------------------

QT       += core gui
LIBS     += -lfftw3 -lm -lphonon
INCLUDEPATH  += /usr/include/phonon # Ooh, this is not nice

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = AutoEQ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    eqalgorithm.cpp \
    core.cpp \
    aboutform.cpp \
    analysingdialog.cpp

HEADERS  += mainwindow.h \
    eqalgorithm.h \
    core.h \
    aboutform.h \
    analysingdialog.h

FORMS    += mainwindow.ui \
    aboutform.ui \
    analysingdialog.ui

RESOURCES += \
    pictures.qrc
