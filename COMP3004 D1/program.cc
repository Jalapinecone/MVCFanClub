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
// #include "conversion.h"

program::program(){

}
void program::changeName(string inputStr)
{
        this->filename = inputStr;
	this->lines = {};
}

program::~program(){

}

void program::compile(){
        cout << "compile program IN THE PROGRAM CLASS" << endl;
	for(unsigned i = 0; i != lines.size(); i++) {
    		createStatement(i);
	}

	cout << "enter file name with .json to save compiled code: ";
	cin >> jsonName;
	cout<<endl;
	QString name = QString::fromStdString(jsonName);
	saveJson(name);
}

void program::execute(){
        cout << "run program" << endl;
}

void program::createStatement(int i){
	string line_no_comment = lines[i].substr(0, lines[i].find('#', 0));
	if (line_no_comment.length() > 1) {
		cout << line_no_comment << endl;
		split(line_no_comment);
		char* label = words[0];
		if (&label[(strlen(label) - 1)] == ":") {
			identifiers.push_back(new identifier(string(words[0])));
		}
		else if (strcmp(words[0], "dci") == 0) {
			cout << "compile dci" << endl;
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				cout << "Failed to compile: Identifier already exists";
			}
			else {
				statements.push_back(new declintstmt(line_no_comment));
				identifiers.push_back(new identifier(string(words[1])));
			}
		}
		else if (strcmp(words[0], "rdi") == 0) {
			cout << "compile rdi" << endl;
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new readstmt(line_no_comment));
			}
			else{
				cout << "Failed to compile: No identifier with that name exists";
			}
		}
		else if (strcmp(words[0], "prt") == 0) {
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new printstmt(line_no_comment));
			}
			else {
				cout << "Failed to compile: No identifier with that name exists";
			}
		}
		else if (strcmp(words[0], "cmp") == 0) {
			bool okay = identifierCheck(string(words[1]));
			bool okay2 = identifierCheck(string(words[2]));
			if (okay && okay2) {
				statements.push_back(new compstmt(line_no_comment));
				compare = true;
			}
			else {
				cout << "Failed to compile: No identifier with that name exists";
			}
		}
		else if (strcmp(words[0], "jmr") == 0) {
			if (compare) {
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new jmorestmt(line_no_comment));
				}
				else {
					cout << "Failed to compile: No identifier with that name exists";
				}
			}
			else {
				cout << "Failed to compile: No compare instruction";
			}
		}
		else if (strcmp(words[0], "jmp") == 0) {
			bool okay = identifierCheck(string(words[1]));
			if (okay) {
				statements.push_back(new jumpstatement(line_no_comment));
			}
			else {
				cout << "Failed to compile: No identifier with that name exists";
			}
		}
		else if (strcmp(words[0], "end") == 0) {
			statements.push_back(new endstmt(line_no_comment));
		}
		else {
			cout << "Failed to compile: Invalid command found: " << words[0] << endl;

		}
	}
}

void program::print(){
	cout << "print program" << endl;
}

void program::split(string line_no_comment){
	char *start = &line_no_comment[0];
	for (char *character = strtok(start," "); character != nullptr; character = strtok(nullptr, " ")){
        words.push_back(start);
	}
}

bool program::identifierCheck(string ident) {
	for (auto &i : identifiers) {
		string name = i->getName();
		if (name == ident) {
			return true;
		}
	}
	return false;
}


void program::saveJson(QString path)
{
	QFile file (path);
    QTextStream out (&file);
	vector <QJsonObject> objs;
    
	if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << "File Opening Error"<<endl;
    }

	int num = 0;
    for (auto &s : statements)
    {
        QJsonObject json;
		json["name"]  = num;

		for (auto &d: s->operands)
		{
        	json["operand " + num] = d;
		}

        QJsonDocument doc(json);
		QString text (doc.toJson(QJsonDocument::Compact));
		out << text;
		num++;
    }
	 file.flush();
     file.close();
}

// vector<operand> program :: getOperand(statement s)
// {
// 	return s->getOperands();
// }