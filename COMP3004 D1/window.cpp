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
    //this links the signal sent when the save button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnSave, SIGNAL (released()), this, SLOT (btnSaveHandler()));

    btnLoad = new QPushButton("Load", this);
    btnLoad->setToolTip("Load a SCAPES program from disk");
    btnLoad->setGeometry(190,10,80,30);
    //this links the signal sent when the load button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnLoad, SIGNAL (released()), this, SLOT (btnLoadHandler()));

    btnCompile = new QPushButton("Compile", this);
    btnCompile->setToolTip("Compile the loaded SCAPES program");
    btnCompile->setGeometry(280,10,80,30);
    //this links the signal sent when the compile button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnCompile, SIGNAL (released()), this, SLOT (btnSaveHandler()));

    btnRun = new QPushButton("Run", this);
    btnRun->setToolTip("Run the compiled SCAPES program");
    btnRun->setGeometry(370,10,80,30);
    //this links the signal sent when the run button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnRun, SIGNAL (released()), this, SLOT (btnSaveHandler()));

    btnManage = new QPushButton("ManagePrefs", this);
    btnManage->setToolTip("Manage Preferences");
    btnManage->setGeometry(460,10,120,30);
    //this links the signal sent when the managePrefs button is hit with the function handler. (participant, signal (type), object where button belongs, slot (handler))
    connect(btnManage, SIGNAL (released()), this, SLOT (btnSaveHandler()));

    txtCodeIn = new QPlainTextEdit(this);
    txtCodeIn->setGeometry(10, 50, 780, 540);

}

//Creates the handlers for the various button options
void Window::btnCreateHandler(){
 	cout << "create handler" << endl;
     	main_ptr->createProg();
}

void Window::btnSaveHandler(){
	cout << "save handler" << endl;
	main_ptr->saveProg();
}
void Window::btnLoadHandler(){
	cout << "load handler" << endl;
	main_ptr->loadProg();
}
void Window::btnCompileHandler(){
	cout << "compile handler" << endl;	
 	main_ptr->compileProg();
}
void Window::btnRunHandler(){
	cout << "run handler" << endl;
    	main_ptr->runProg();
}
