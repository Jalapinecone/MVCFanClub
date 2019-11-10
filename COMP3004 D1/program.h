#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include <vector>
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
		vector<string> lines;
		void compile();
		void execute();
		void createStatement(int);
		void split(string);
		void print();
	private:
		int comparisonFlag;
		vector<statement*> statements;
		vector<identifier*> identifiers;
		vector<char*> words;



};
#endif
