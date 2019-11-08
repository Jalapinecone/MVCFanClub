OPT = -Wall

SCAPES: main.o SCAPESmain.o functionInterface.o saveProgram.o createProgram.o identifier.o variable.o operand.o label.o statement.o declIntStmt.o
	g++ $(OPT) -o SCAPES main.o SCAPESmain.o functionInterface.o saveProgram.o createProgram.o identifier.o variable.o operand.o label.o statement.o declIntStmt.o

main.o: main.cc SCAPESmain.h 
	g++ $(OPT) -c main.cc

SCAPESmain.o: SCAPESmain.cc SCAPESmain.h createProgram.h saveProgram.h 
	g++ $(OPT) -c SCAPESmain.cc

functionInterface.o: functionInterface.cc functionInterface.h 
	g++ $(OPT) -c functionInterface.cc

saveProgram.o: saveProgram.cc saveProgram.h functionInterface.h
	g++ $(OPT) -c saveProgram.cc

createProgram.o: createProgram.cc createProgram.h functionInterface.h
	g++ $(OPT) -c createProgram.cc

identifier.o: identifier.cc identifier.h
	g++ $(OPT) -c identifier.cc

variable.o: variable.cc variable.h identifier.h
	g++ $(OPT) -c variable.cc

operand.o: operand.cc operand.h identifier.h
	g++ $(OPT) -c operand.cc

label.o: label.cc label.h identifier.h
	g++ $(OPT) -c label.cc

statement.o: statement.cc statement.h operand.h
	g++ $(OPT) -c statement.cc

declIntStmt.o: declIntStmt.cc declIntStmt.h statement.h
	g++ $(OPT) -c declIntStmt.cc

clean:
	rm -f *.o SCAPES
