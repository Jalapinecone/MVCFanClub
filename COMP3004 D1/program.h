#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include <vector>
#include <QString>
#include "statement.h"
#include "declIntStmt.h"
#include "readStmt.h"
#include "printStmt.h"
#include "compStmt.h"
#include "jMoreStmt.h"
#include "jumpStatement.h"
#include "endStmt.h"






class program
{
	public:
		program();
		void changeName(string);
		~program();
		string filename;
		string jsonName;
		vector<string> lines;
		void compile();
		void execute();
		void createStatement(int);
		vector <char *> split(string);
		void print();
		bool identifierCheck(string);
		void saveJson();
	private:
		int comparisonFlag;
		vector<statement*> statements;
		vector<identifier*> identifiers;
		bool compare = false;



};
#endif
