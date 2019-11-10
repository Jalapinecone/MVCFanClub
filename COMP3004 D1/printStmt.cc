#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "printStmt.h"

printstmt::printstmt(string inst){

	instructions = inst;
	compile(inst);
}

printstmt::~printstmt(){

}

void printstmt::compile(string inst){
	
}

void printstmt::run(){

}
