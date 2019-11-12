#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <QDebug>
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
using namespace std;

#include "program.h"

program::program(){

}
void program::changeName(string inputStr)
{
	this->filename = inputStr;
	this->lines = {};
}

program::~program(){

}

//creates a new compiled statement object
void program::compile(){
    cout << "compile program IN THE PROGRAM CLASS" << endl;
	for(unsigned i = 0; i != lines.size(); i++) {
    		createStatement(i);
	}

	//calls the function to convert the compiled objects to json format and saves them
	this->saveJson();
}

//Not used for D1
void program::execute(){
    cout << "run program" << endl;
}

//Main statement creation
void program::createStatement(int i){
	cout << "_________________________" << endl;
	cout << "CREATE STATEMENT" << endl;
	cout << "i: " << i << endl;
    vector<char*> words;	

	//stores the entered statement without any inline comments
	string line_no_comment = lines[i].substr(0, lines[i].find('#', 0));
	cout << "LINE NO COMMENT:" << line_no_comment << endl;

	if (line_no_comment.length() > 1) {
		cout << line_no_comment << endl;
		words = split(line_no_comment);
		char* labl = words[0];

		//stores new labels and stores them into an identifiers vector
		if (labl[(strlen(labl) - 1)] == ':') {
			identifiers.push_back(new label(string(words[0])));
		}

		//stores new dci statements, checking to see if the identifier exists already, 
		//then stores the statement in a vector and its variable in another vector
		else if (strcmp(words[0], "dci") == 0) {
			cout << "compile dci" << endl;
			bool okay = identifierCheck(string(words[1]));
			
			if (okay) {
				cout << "Failed to compile: Identifier already exists" << endl;
			}
			else {
				statements.push_back(new declintstmt(line_no_comment));
				identifiers.push_back(new variable(string(words[1])));
				cout << "dci compiled" << endl;
			}
		}

		//stores new rdi statements, checking to see if the identifier exists already, 
		//then stores the statement in a vector
		else if (strcmp(words[0], "rdi") == 0) {
			cout << "compile rdi" << endl;
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new readstmt(line_no_comment));
				cout << "rdi compiled" << endl;
			}
			else{
				cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[1] << "' exists: " << endl;
			}
		}

		//stores new prt statements, checking to see if the given identifiers exists,
		//then stores the statement in a vector
		else if (strcmp(words[0], "prt") == 0) {
			cout << "compile prt" << endl;
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new printstmt(line_no_comment));
			}
			else {
				cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[1] << "' exists: " << endl;
			}
		}

		//stores new cmp statements, checking to see if the identifiers exists already, 
		//then stores the statement in a vector
		else if (strcmp(words[0], "cmp") == 0) {
			cout << "compile cmp" << endl;
			bool okay = identifierCheck(string(words[1]));
			bool okay2 = identifierCheck(string(words[2]));
			if (okay && okay2) {
				statements.push_back(new compstmt(line_no_comment));
				compare = true;
			}
			else {
				cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier(s) with name ";
				if(!okay){
					cout << " '" << words[1] << "' ";
				}
				if(!okay && !okay2){
					cout << " and ";
				}
				if(!okay2){
					cout << " '" << words[2] << "' ";
				}
				cout << " exist. " << endl;
			}
		}

		//stores new jmr statements, checking to see if the identifier exists already, 
		//then stores the statement in a vector
		else if (strcmp(words[0], "jmr") == 0) {
			cout << "compile jmr" << endl;
			if (compare) {
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new jmorestmt(line_no_comment));
				}
				else {
					cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[1] << "' exists: " << endl;
				}
			}
			else {
				cout << "Failed to compile: No compare instruction: " << endl;
			}
		}

		//stores new jmp statements, checking to see if the identifier exists already, 
		//then stores the statement in a vector
		else if (strcmp(words[0], "jmp") == 0) {
			cout << "compile jmp" << endl;
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new jumpstatement(line_no_comment));
			}
			else {
				cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[1] << "' exists: " << endl;
			}
		}

		//stores new end statements, checking to see if the identifier exists already, 
		//then stores the statement in a vector
		else if (strcmp(words[0], "end") == 0) {
			cout << "compile end" << endl;
			statements.push_back(new endstmt(line_no_comment));
		}

		//Error check for any invalid commands entered
		else {
			cout << "Failed to compile: Invalid command found: " << words[0] << endl;

		}
	}
}

void program::print(){
	cout << "print program" << endl;
}

//Used to split up the instruction string into its different elements
vector<char *> program::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];

	//This takes a vector of words, sending the characters to a string a vector until a "" is reached
	char *character = strtok(str," ");

	//Adds the words to a vector if they are not null
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}

//Function used to see if the identifier exists 
bool program::identifierCheck(string ident) {
	cout << "IDENTIFIERCHECK" << endl;

	for (auto &i : identifiers) {
		cout << "i->getName(): " << i->getName() << endl;
		cout << "ident: " << ident << endl;

		string name = i->getName();
		cout << "NAME: " << name << endl;
		if (name == ident) {
			return true;
		}
	}
	return false;
}


//Function used to convert objects to json and save them to a file
void program::saveJson()
{
	QJsonObject Program;

	//Sets the objects filename
	Program["filename"] = QString::fromStdString(this->filename);
	QJsonArray jsa;

	//Loops through the statements vector
    for (auto &s : statements)
    {
        QJsonObject jst;

		//Sets the objects instruction parameter
		jst["instruction"]  = QString::fromStdString(s->getInstruction());
		QJsonArray joa;

		//Loops through the current statement's operand vector
		for (auto &o: s->getOperands())
		{
			QJsonObject jop;

			//Stores the objects operand name
        	jop["name"] = QString::fromStdString(o->getName());
			joa.push_back(jop);
		}

		//Lists all of the object's operands, saving them to the upper object
		jst["operands"] = joa;
		jsa.push_back(jst);
    }

	//Sets the full object's attributes: 
    Program["statements"] = jsa;

	//Opens a json document and asks the user for a .json file name
    QJsonDocument doc(Program);
    cout << "enter file name with .json to save compiled code: ";
    cin >> jsonName;
    cout<<endl;

	//Opens/creates the file for writing only, then saves the full json object to it
    QFile file(QString::fromStdString(jsonName));
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
}
