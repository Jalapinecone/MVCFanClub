TEMPLATE = app
TARGET = SCAPES

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    windowInterface.cc
    variable.cc
    statement.cc
    SCAPESmain.cc
    saveProgram.cc
    runProgram.cc
    readStmt.cc
    program.cc
    printStmt.cc
    operand.cc
    manageSystemPrefs.cc
    loadProgram.cc
    label.cc
    jumpStatement.cc
    jMoreStmt.cc
    identifier.cc
    functionInterface.cc
    endStmt.cc
    editProgram.cc
    declIntStmt.cc
    createProgram.cc
    compStmt.cc
    compileProgram.cc

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
    windowInterface.h
    variable.h
    statement.h
    SCAPESmain.h
    saveProgram.h
    runProgram.h
    readStmt.h
    program.h
    printStmt.h
    operand.h
    manageSystemPrefs.h
    loadProgram.h
    label.h
    jumpStatement.h
    jMoreStmt.h
    identifier.h
    functionInterface.h
    endStmt.h
    editProgram.h
    declIntStmt.h
    createProgram.h
    compStmt.h
    compileProgram.h
