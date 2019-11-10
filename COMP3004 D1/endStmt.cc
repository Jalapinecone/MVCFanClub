#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "endStmt.h"

endstmt::endstmt(string inst){

	instructions = inst;
	compile(inst);
}

endstmt::~endstmt(){

}

void endstmt::compile(string inst){
	
}

void endstmt::run(){

}
