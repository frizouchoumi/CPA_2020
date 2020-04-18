all : DatabasePinTovector.o 
	g++ DatabasePinTovector.o main.cpp -o main
DatabasePinTovector.o: DatabasePinTovector.cpp  DatabasePinTovector.h
	g++ -c DatabasePinTovector.cpp
clean : 
	del *.o
	