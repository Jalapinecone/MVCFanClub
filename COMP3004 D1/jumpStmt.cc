#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "jumpStmt.h"

jumpstmt::jumpstmt(string inst){

	instructions = inst;
	compile(inst);
}

jumpstmt::~jumpstmt(){

}

void jumpstmt::compile(string inst){
	
}

void jumpstmt::run(){

}
