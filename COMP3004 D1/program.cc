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

//Allows to change the name of the program and reset the lines
void program::changeName(string inputStr)
{
    this->filename = inputStr;
	this->lines = {};
	this->err = false;
}

//In charge of unallocating dynamically allocated memory
program::~program(){
	for (auto &s : statements)
	{
		for(auto &d: s->getOperands())
		{
			delete(d);
		}
		for(auto &n: s->getLabels())
		{
			delete(n);
		}
		delete(s);
	}
}

//Used to compile the program
void program::compile(){
	//Loop through each line in the file and create a statement for each line
	identifiers.clear();
	statements.clear();
	for(unsigned i = 0; i != lines.size(); i++) {
    		createStatement(i);
	}
	if(!err){

		//save the compile in a Json file
		this->saveJson();
	}
}

//Not used in D1
void program::execute(){
        cout << "run program" << endl;
}

//Creates each statement object
void program::createStatement(int i){
    //Create a vector of char's to store each word in the line
	vector<char*> words;
	//Parse each line to remove comments
	string line_no_comment = lines[i].substr(0, lines[i].find(" #", 0));
	line_no_comment = line_no_comment.substr(0, lines[i].find('#', 0));
	//make sure that there is atleast 1 word in the string
	if (line_no_comment.length() > 1) {
		//split each line into words
		words = split(line_no_comment);
		//check to see if there will be a label as the first word in the line
		char* labl = words[0];
		//Check to see if 'end' has been called
		if(!done){
			//If there is a label as the first word in the line
			if (labl[(strlen(labl) - 1)] == ':') {
				//check to see if the label already exists
		                bool okay = identifierCheck(string(words[0]));
				if (!okay){
					//If the label doesn't exist create it
                    			identifiers.push_back(new label(string(words[0])));
					//stores new dci statements, checking to see if the identifier exists already, 
					//then stores the statement in a vector and its variable in another vector
					if (strcmp(words[1], "dci") == 0) {
						wordSize(words.size(),3);
						bool okay = identifierCheck(string(words[2]));
	                	        	if (okay) {
	                	                	errors.insert(errors.begin(),"Failed to compile: Identifier already exists");
							err = true;
						}
	                	        	else {
	                	                	statements.push_back(new declintstmt(line_no_comment));
	 		                               	identifiers.push_back(new variable(string(words[2])));
	 		                       	}
					}
					//stores new rdi statements, checking to see if the identifier exists already,
					//then stores the statement in a vector
					else if(strcmp(words[1], "rdi") == 0) {
						wordSize(words.size(),3);
		                       	 	bool okay = identifierCheck(string(words[2]));
		                        	if (okay) {
		                                	statements.push_back(new readstmt(line_no_comment));
		                        	}
		                        	else{
		                                	errors.insert(errors.begin(),"Failed to compile line " + to_string(i+1) + ": '" + line_no_comment + "' No identifier with that name '" + string(words[2]) + "' exists: ");
		                        		err = true;
						}
					}
					//stores new prt statements, checking to see if the given identifiers exists,
					//then stores the statement in a vector
					else if (strcmp(words[1], "prt") == 0) {
                                                wordSize(words.size(),3);
						bool okay = identifierCheck(string(words[2]));
			                        if (okay) {
			                                statements.push_back(new printstmt(line_no_comment));
			                        }
			                        else {
			                                errors.insert(errors.begin(),"Failed to compile line " + to_string(i + 1) + ": '" + line_no_comment + "' No identifier with that name '" + string(words[2]) + "' exists: ");
			                        	err = true;
						}
			                }
					//stores new cmp statements, checking to see if the identifiers exists already, 
					//then stores the statement in a vector
					else if (strcmp(words[1], "cmp") == 0) {
                                                wordSize(words.size(),4);
			                        bool okay = identifierCheck(string(words[2]));
			                        bool okay2 = identifierCheck(string(words[3]));
			                        if (okay && okay2) {
			                                statements.push_back(new compstmt(line_no_comment));
			                                compare = true;
			                        }
			                        else {
			                                errors.insert(errors.begin(),"Failed to compile line " + to_string(i+1) + ": '" + line_no_comment);
							err = true;
						}
					}
					//stores new jmr statements, checking to see if the identifier exists already, 
					//then stores the statement in a vector
					else if (strcmp(words[1], "jmr") == 0) {
                                                wordSize(words.size(),3);
		        	                bool okay = identifierCheck(string(words[2]));
		        	                if (okay) {
		        	                	statements.push_back(new jmorestmt(line_no_comment));
		        	                }
		        	                else {
			        	                identifiers.push_back(new label(string(words[2])));
							statements.push_back(new jmorestmt(line_no_comment));
		        	                }
					}
					//stores new jmp statements, checking to see if the identifier exists already, 
					//then stores the statement in a vector
					else if (strcmp(words[1], "jmp") == 0) {
                                                wordSize(words.size(),3);
		                        	bool okay = identifierCheck(string(words[2]));
		                        	if (okay) {
	        	                	        statements.push_back(new jumpstatement(line_no_comment));
	        	                	}
	        	                	else {
							identifiers.push_back(new label(string(words[2])));
							statements.push_back(new jumpstatement(line_no_comment));
	
      			                  	}
					}
					//stores new end statements, then stores the statement in a vector
					else if (strcmp(words[1], "end") == 0) {
                                                wordSize(words.size(),2);
		                        	statements.push_back(new endstmt(line_no_comment));
			                	}
					//If the command is invalid
		            else {
		            	        errors.insert(errors.begin(),"Failed to compile: Invalid command found: " + string(words[1]) + " ");
					err = true;
		            }
				}
				//if the label already exists
				else{
					errors.insert(errors.begin(), "Label: " + string(words[0]) + " already exists");	
					err = true;
				}
			}
//When there is no label as the first word 

			//stores new dci statements, checking to see if the identifier exists already, 
			//then stores the statement in a vector and its variable in another vector
			else if (strcmp(words[0], "dci") == 0) {
                                wordSize(words.size(),2);
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					errors.insert(errors.begin(),"Failed to compile: Identifier already exists");
					err = true;
				}
				else {
					statements.push_back(new declintstmt(line_no_comment));
					identifiers.push_back(new variable(string(words[1])));
				}
			}
			//stores new rdi statements, checking to see if the identifier exists already, 
			//then stores the statement in a vector
			else if (strcmp(words[0], "rdi") == 0) {
                                wordSize(words.size(),2);
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new readstmt(line_no_comment));
				}
				else{
					errors.insert(errors.begin(),"Failed to compile line " + to_string(i+1) + ": '" + line_no_comment + "' No identifier with that name '" + string(words[1]) + "' exists ");
					err = true;
				}
			}
			//stores new prt statements, checking to see if the given identifiers exists,
			//then stores the statement in a vector
			else if (strcmp(words[0], "prt") == 0) {
                                wordSize(words.size(),2);
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new printstmt(line_no_comment));
				}
				else {
					errors.insert(errors.begin(),"Failed to compile line " + to_string(i+1) + ": '" + line_no_comment + "' No identifier with that name '" + string(words[1]) + "' exists ");
					err = true;
				}
			}
			//stores new cmp statements, checking to see if the identifiers exists already, 
			//then stores the statement in a vector
			else if (strcmp(words[0], "cmp") == 0) {
                                wordSize(words.size(),3);
				bool okay = identifierCheck(string(words[1]));
				bool okay2 = identifierCheck(string(words[2]));
				if (okay && okay2) {
					statements.push_back(new compstmt(line_no_comment));
					compare = true;
				}
				else {
					errors.insert(errors.begin(), "Failed to compile line " + to_string(i+1) + ": '" + line_no_comment + "' No identifier(s) with that name ");
					err = true;
				}
			}
			//stores new jmr statements, checking to see if the identifier exists already, 
			//then stores the statement in a vector
			else if (strcmp(words[0], "jmr") == 0) {
				if (compare) {
	                                wordSize(words.size(),2);
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
					errors.insert(errors.begin(), "Failed to compile: No compare instruction ");
					err = true;
				}
			}
			//stores new jmp statements, checking to see if the identifier exists already, 
			//then stores the statement in a vector
			else if (strcmp(words[0], "jmp") == 0) {
                                wordSize(words.size(),2);
				bool okay = identifierCheck(string(words[1]));
				if (okay) {
					statements.push_back(new jumpstatement(line_no_comment));
				}
				else {
					identifiers.push_back(new label(string(words[1])));
					statements.push_back(new jumpstatement(line_no_comment));
	
				}
			}
			//stores new end statements, then stores the statement in a vector
			else if (strcmp(words[0], "end") == 0) {
                                wordSize(words.size(),1);
				statements.push_back(new endstmt(line_no_comment));
				//changes done to be true to not create any new statements
				done = true;
			}
			//Error check for any invalid commands entered
			else {
				errors.insert(errors.begin(),"Failed to compile: Invalid command found: " + string(words[0]));
				err = true;
			}
		}
	}
}

void program::print(){
	cout << "print program" << endl;
}


//Used to split up the instruction string into its different elements
vector<char *> program::split(string line_no_comment) {
	vector <char *> words;
	char *str = &line_no_comment[0];

	//This takes a vector of words, sending the characters to a string a vector until a "" is reached
	char *character = strtok(str, " ");

	//Adds the words to a vector if they are not null
	while (character != NULL) {
		words.push_back(character);
		character = strtok(NULL, " ");
	}
	return words;
}

//Function used to see if the identifier exists 
bool program::identifierCheck(string ident) {
	for (auto &i : identifiers) {
		string name = i->getName();
		if (name == ident) {
			return true;
		}
	}
	return false;
}

//Checks to see if the correct number of operands are listed
void program::wordSize(int ws,int rs){
	if (ws != rs) {
        	errors.insert(errors.begin(), "Could not compile, statement requires: " + to_string(ws-1)+ "operands to compile");
                        err = true;
                }
}




//Function used to convert objects to json and save them to a file
void program::saveJson()
{
	QJsonObject Program;

	//Sets the objects filename
	Program["filename"] = QString::fromStdString(this->filename);

	//Create json array
	QJsonArray jsa;

	//Loops through the statements vector
    for (auto &s : statements)
    {

		//Create json object
        QJsonObject jst;

		//Sets the objects instruction parameter
	jst["instruction"]  = QString::fromStdString(s->getInstruction());

	//Loops through the current statement's label vector
	for (auto &l : s->getLabels())
	{
		//Store the labels name
		jst["label"] = QString::fromStdString(l->getName());
	}
	//Create Json array
	QJsonArray joa;

	//Loops through the current statement's operand vector
		for (auto &o: s->getOperands())
		{
			//create json object
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
	jsonName = filename + ".json";
	errors.insert(errors.begin(), "Compile Successful!");
	//Opens/creates the file for writing only, then saves the full json object to it
    QFile file(QString::fromStdString(jsonName));
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
}

//Setter for the compare boolean (set each time compile is loaded)
void program::setCompare(bool comp){
	compare = comp;
}

//Setter for the done boolean (set each time compile is loaded)
void program::setDone(bool d){
	done = d;
}

//Setter for the err boolean (set each time compile is loaded)
void program::setError(bool error){
	err = error;
}
