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
#include "jumpStmt.h"
#include "endStmt.h"






class program
{
	public:
		program();
		program(string);
		~program();
		string filename;
		void compile();
		void execute();
		void createStatement(string);
		vector<char*> split(string);
		void print();
	private:
		int comparisonFlag;
		vector<statement*> statements;
		vector<identifier*> identifiers;
		vector<char*> words;



};
#endif