#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "readStmt.h"

readstmt::readstmt(string inst){

	instructions = inst;
	compile(inst);
}

readstmt::~readstmt(){

}

void readstmt::compile(string inst){
	
}

void readstmt::run(){

}
