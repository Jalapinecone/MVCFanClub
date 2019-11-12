//Created by Jared on 10/11/2019
//This is the object where the GUI is constructed and the event handlers are located

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QString>
#include "windowInterface.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

private slots:
    std::string qstringToString(QString q);
    void btnCreateHandler();
    void btnSaveHandler();
    void btnLoadHandler();
    void btnCompileHandler();
    //void btnRunHandler();
private:
    QPushButton *btnCreate;
    QPushButton *btnSave;
    //QPushButton *btnLoad;
    QPushButton *btnCompile;
    //QPushButton *btnRun;
    //QPushButton *btnManage;
    QLineEdit *txtExtraInput;
    QPlainTextEdit *txtCodeIn;
    QPlainTextEdit *txtFdbkOut;
    WindowInterface *main_ptr;
};

#endif // WINDOW_H
