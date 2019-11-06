OPT = -Wall

SCAPES: main.o SCAPESmain.o functionInterface.o saveProgram.o createProgram.o
	g++ $(OPT) -o SCAPES main.o SCAPESmain.o functionInterface.o saveProgram.o createProgram.o

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
clean:
	rm -f *.o SCAPES
