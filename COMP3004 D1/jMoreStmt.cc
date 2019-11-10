#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "jMoreStmt.h"

jmorestmt::jmorestmt(string inst){

	instructions = inst;
	compile(inst);
}

jmorestmt::~jmorestmt(){

}

void jmorestmt::compile(string inst){
	
}

void jmorestmt::run(){

}
