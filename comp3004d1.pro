#-------------------------------------------------
#
# Project created by QtCreator 2019-11-09T17:01:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004_D1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    SCAPESmain.cc \
    compStmt.cc \
    compileProgram.cc \
    createProgram.cc \
    declIntStmt.cc \
    editProgram.cc \
    endStmt.cc \
    functionInterface.cc \
    identifier.cc \
    jMoreStmt.cc \
    jumpStatement.cc \
    label.cc \
    loadProgram.cc \
    main.cpp \
    manageSystemPrefs.cc \
    operand.cc \
    printStmt.cc \
    program.cc \
    readStmt.cc \
    runProgram.cc \
    saveProgram.cc \
    statement.cc \
    variable.cc \
    window.cpp \
    windowInterface.cc

HEADERS += \
    SCAPESmain.h \
    compStmt.h \
    compileProgram.h \
    createProgram.h \
    declIntStmt.h \
    editProgram.h \
    endStmt.h \
    functionInterface.h \
    identifier.h \
    jMoreStmt.h \
    jumpStatement.h \
    label.h \
    loadProgram.h \
    manageSystemPrefs.h \
    operand.h \
    printStmt.h \
    program.h \
    readStmt.h \
    runProgram.h \
    saveProgram.h \
    statement.h \
    variable.h \
    window.h \
    windowInterface.h

FORMS += \
        conversion.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
