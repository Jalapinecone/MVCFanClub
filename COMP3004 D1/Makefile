OPT = -Wall

SCAPES: main.o SCAPESmain.o functionInterface.o loadProgram.o saveProgram.o createProgram.o runProgram.o editProgram.o compileProgram.o manageSystemPrefs.o identifier.o variable.o operand.o label.o
	g++ $(OPT) -o SCAPES main.o SCAPESmain.o functionInterface.o loadProgram.o saveProgram.o createProgram.o runProgram.o editProgram.o compileProgram.o manageSystemPrefs.o identifier.o variable.o operand.o label.o

main.o: main.cc SCAPESmain.h 
	g++ $(OPT) -c main.cc

SCAPESmain.o: SCAPESmain.cc SCAPESmain.h createProgram.h saveProgram.h loadProgram.h runProgram.h editProgram.h compileProgram.h manageSystemPrefs.h 
	g++ $(OPT) -c SCAPESmain.cc

functionInterface.o: functionInterface.cc functionInterface.h 
	g++ $(OPT) -c functionInterface.cc

loadProgram.o: loadProgram.cc loadProgram.h functionInterface.h
	g++ $(OPT) -c loadProgram.cc

saveProgram.o: saveProgram.cc saveProgram.h functionInterface.h
	g++ $(OPT) -c saveProgram.cc

createProgram.o: createProgram.cc createProgram.h functionInterface.h
	g++ $(OPT) -c createProgram.cc

runProgram.o: runProgram.cc runProgram.h functionInterface.h
	g++ $(OPT) -c runProgram.cc

editProgram.o: editProgram.cc editProgram.h functionInterface.h
	g++ $(OPT) -c editProgram.cc

compileProgram.o: compileProgram.cc compileProgram.h functionInterface.h
	g++ $(OPT) -c compileProgram.cc

manageSystemPrefs.o: manageSystemPrefs.cc manageSystemPrefs.h functionInterface.h
	g++ $(OPT) -c manageSystemPrefs.cc

identifier.o: identifier.cc identifier.h
	g++ $(OPT) -c identifier.cc

variable.o: variable.cc variable.h identifier.h
	g++ $(OPT) -c variable.cc

operand.o: operand.cc operand.h identifier.h
	g++ $(OPT) -c operand.cc

label.o: label.cc label.h identifier.h
	g++ $(OPT) -c label.cc


clean:
	rm -f *.o SCAPES
