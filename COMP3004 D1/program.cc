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

	this->saveJson();
}

void program::execute(){
        cout << "run program" << endl;
}

void program::createStatement(int i){
	cout << "_________________________" << endl;
	cout << "CREATE STATEMENT" << endl;
	cout << "i: " << i << endl;
        vector<char*> words;	
	string line_no_comment = lines[i].substr(0, lines[i].find('#', 0));
	cout << "LINE NO COMMENT:" << line_no_comment << endl;
	if (line_no_comment.length() > 1) {
		cout << line_no_comment << endl;
		words = split(line_no_comment);
		char* labl = words[0];
		if(!done){
			if (labl[(strlen(labl) - 1)] == ':') {
		                bool okay = identifierCheck(string(words[0]));
				if (!okay){
                                        identifiers.push_back(new label(string(words[0])));
					if (strcmp(words[1], "dci") == 0) {
						bool okay = identifierCheck(string(words[2]));
	                	        	if (okay) {
	                	                	cout << "Failed to compile: Identifier already exists" << endl;
	                	        	}
	                	        	else {
							cout << "TET" << endl;
	                	                	statements.push_back(new declintstmt(line_no_comment));
	 		                               	identifiers.push_back(new variable(string(words[2])));
	 		                       	}
					}
					else if(strcmp(words[1], "rdi") == 0) {
		                        	cout << "compile rdi" << endl;
		                       	 	bool okay = identifierCheck(string(words[2]));
		                        	if (okay) {
		                                	statements.push_back(new readstmt(line_no_comment));
		                                	cout << "rdi compiled" << endl;
		                        	}
		                        	else{
		                                	cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[2] << "' exists: " << endl;
		                        	}
					}
					else if (strcmp(words[1], "prt") == 0) {
			                        cout << "compile prt" << endl;
			                        bool okay = identifierCheck(string(words[2]));
			                        if (okay) {
			                                statements.push_back(new printstmt(line_no_comment));
			                        }
			                        else {
			                                cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier with that name '" << words[2] << "' exists: " << endl;
			                        }
			                }
					else if (strcmp(words[1], "cmp") == 0) {
			                        cout << "compile cmp" << endl;
			                        bool okay = identifierCheck(string(words[2]));
			                        bool okay2 = identifierCheck(string(words[3]));
			                        if (okay && okay2) {
			                                statements.push_back(new compstmt(line_no_comment));
			                                compare = true;
			                        }
			                        else {
			                                cout << "Failed to compile line " << i << ": '" << line_no_comment << "' No identifier(s) with name ";
			                                if(!okay){
			                                        cout << " '" << words[2] << "' ";
			                                }
			                                if(!okay && !okay2){
			                                        cout << " and ";
			                                }
			                                if(!okay2){
			                                        cout << " '" << words[3] << "' ";
			                                }
			                                cout << " exist. " << endl;
			                        }
					}
					else if (strcmp(words[1], "jmr") == 0) {
			                        cout << "compile jmr" << endl;
			                        if (compare) {
		        	                        bool okay = identifierCheck(string(words[2]));
		        	                        if (okay) {
		        	                                statements.push_back(new jmorestmt(line_no_comment));
		        	                        }
		        	                        else {
			        	                        identifiers.push_back(new label(string(words[2])));
								statements.push_back(new jmorestmt(line_no_comment));
							}
		        	                }
		        	                else {
		        	                        cout << "Failed to compile: No compare instruction: " << endl;
		        	                }
		        	        }
					else if (strcmp(words[1], "jmp") == 0) {
		                        	cout << "compile jmp" << endl;
		                        	bool okay = identifierCheck(string(words[2]));
		                        	if (okay) {
	        	                	        statements.push_back(new jumpstatement(line_no_comment));
	        	                	}
	        	                	else {
							identifiers.push_back(new label(string(words[2])));
							statements.push_back(new jumpstatement(line_no_comment));
	
      			                  	}
					}
					else if (strcmp(words[1], "end") == 0) {
		                        	cout << "compile end" << endl;
		                        	statements.push_back(new endstmt(line_no_comment));
			                	}
		                	else {
		                	        cout << "Failed to compile: Invalid command found: " << words[0] << endl;
		
		                	}
				}
				else{
					cout << "Label: " << words[0] << " already exists" <<endl;	
				}
			}
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
			else if (strcmp(words[0], "jmr") == 0) {
				cout << "compile jmr" << endl;
				if (compare) {
					bool okay = identifierCheck(string(words[1]));
					if (okay) {
						statements.push_back(new jmorestmt(line_no_comment));
					}
					else {
						identifiers.push_back(new label(string(words[1])));
						statements.push_back(new jumpstatement(line_no_comment));
					}
				}
				else {
					cout << "Failed to compile: No compare instruction: " << endl;
				}
			}
			else if (strcmp(words[0], "jmp") == 0) {
				cout << "compile jmp" << endl;
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new jumpstatement(line_no_comment));
				}
				else {
					identifiers.push_back(new label(string(words[1])));
					statements.push_back(new jumpstatement(line_no_comment));
	
				}
			}
			else if (strcmp(words[0], "end") == 0) {
				cout << "compile end" << endl;
				statements.push_back(new endstmt(line_no_comment));
				done = true;
			}
			else {
				cout << "Failed to compile: Invalid command found: " << words[0] << endl;
	
			}
		}
	}
}

void program::print(){
	cout << "print program" << endl;
}

vector<char *> program::split(string line_no_comment){
	vector <char *> words;
	char *str = &line_no_comment[0];
	char *character = strtok(str," ");
	while (character != NULL){
		words.push_back(character);
		character = strtok(NULL," ");
	}
		return words;
}

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


void program::saveJson()
{
	QJsonObject Program;
	Program["filename"] = QString::fromStdString(this->filename);
	QJsonArray jsa;
    for (auto &s : statements)
    {
        QJsonObject jst;
	jst["instruction"]  = QString::fromStdString(s->getInstruction());
	for (auto &l : s->getLabels())
	{
		cout << "BLAAAAAAAGGGGGGHHHHHH" << endl;
		jst["label"] = QString::fromStdString(l->getName());
	}
	QJsonArray joa;
		for (auto &o: s->getOperands())
		{
			QJsonObject jop;
        		jop["name"] = QString::fromStdString(o->getName());
			joa.push_back(jop);
		}
		jst["operands"] = joa;
		jsa.push_back(jst);
    }
    Program["statements"] = jsa;
    QJsonDocument doc(Program);
    cout << "enter file name with .json to save compiled code: ";
    cin >> jsonName;
    cout<<endl;
    QFile file(QString::fromStdString(jsonName));
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
}
