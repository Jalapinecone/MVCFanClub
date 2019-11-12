#include "window.h"
using namespace std;

Window::Window(QWidget *parent): QWidget (parent)
{
    main_ptr = new WindowInterface();
    //set window size
    setFixedSize(800,600);

    btnCreate = new QPushButton("Create", this);
    btnCreate->setToolTip("Create a new SCAPES program");
    btnCreate->setGeometry(10,10,80,30);
    //this links the signal sent when the create button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnCreate, SIGNAL (released()), this, SLOT (btnCreateHandler()));

    btnSave = new QPushButton("Save", this);
    btnSave->setToolTip("Save a SCAPES program to disk");
    btnSave->setGeometry(100,10,80,30);
    connect(btnSave, SIGNAL (released()), this, SLOT (btnSaveHandler()));

/*  //Load Button ***Crashes if target file does not exist***
    btnLoad = new QPushButton("Load", this);
    btnLoad->setToolTip("Load a SCAPES program from disk");
    btnLoad->setGeometry(190,10,80,30);
    connect(btnLoad, SIGNAL (released()), this, SLOT (btnLoadHandler()));
*/
    btnCompile = new QPushButton("Compile", this);
    btnCompile->setToolTip("Compile the loaded SCAPES program");
    btnCompile->setGeometry(280,10,80,30);
    connect(btnCompile, SIGNAL (released()), this, SLOT (btnCompileHandler()));
/*  //Run Button -
    btnRun = new QPushButton("Run", this);
    btnRun->setToolTip("Run the compiled SCAPES program");
    btnRun->setGeometry(370,10,80,30);
    connect(btnRun, SIGNAL (released()), this, SLOT (btnRunHandler()));

    btnManage = new QPushButton("ManagePrefs", this);
    btnManage->setToolTip("Manage Preferences");
    btnManage->setGeometry(460,10,120,30);
    connect(btnManage, SIGNAL (released()), this, SLOT (btnSaveHandler()));
*/
    txtExtraInput = new QLineEdit(this);
    txtExtraInput->setGeometry(10, 50, 780, 30);
    txtExtraInput->setText("");
    //this is the code editor box
    txtCodeIn = new QPlainTextEdit(this);
    txtCodeIn->setGeometry(10, 90, 480, 500);
    //this is the output box
    txtFdbkOut = new QPlainTextEdit(this);
    txtFdbkOut->setGeometry(500, 90, 290, 500);

}
//convert qt's QString to a string
std::string Window::qstringToString(QString q){
    return q.toUtf8().constData();
}

//event handlers
void Window::btnCreateHandler(){
     	main_ptr->createProg(qstringToString(txtExtraInput->text()));
}
void Window::btnSaveHandler(){
	main_ptr->saveProg(qstringToString(txtExtraInput->text()), qstringToString(txtCodeIn->toPlainText()));
}
void Window::btnLoadHandler(){
  txtCodeIn->setPlainText(QString::fromStdString(main_ptr->loadProg(qstringToString(txtExtraInput->text()))));
}
void Window::btnCompileHandler(){
	cout << "compile handler" << endl;
 	//string s = main_ptr->compileProg(qstringToString(txtExtraInput->text()), qstringToString(txtCodeIn->toPlainText()));
  txtFdbkOut->setPlainText(QString::fromStdString(main_ptr->compileProg(qstringToString(txtExtraInput->text()), qstringToString(txtCodeIn->toPlainText()))));
}

/*
void Window::btnRunHandler(){
	cout << "run handler" << endl;
    	main_ptr->runProg();
}*/
