#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "compStmt.h"

compstmt::compstmt(string inst){

	instructions = inst;
	compile(inst);
}

compstmt::~compstmt(){

}

void compstmt::compile(string inst){
	
}

void compstmt::run(){

}
