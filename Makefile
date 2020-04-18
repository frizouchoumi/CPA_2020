all : DatabasePinTovector.o pinAnalyser.o
	g++ DatabasePinTovector.o pinAnalyser.o main.cpp -o main
DatabasePinTovector.o: DatabasePinTovector.cpp  DatabasePinTovector.h
	g++ -c DatabasePinTovector.cpp
pinAnalyser.o : pinAnalyser.cpp pinAnalyser.h
	g++ -c pinAnalyser.cpp
clean : 
	del *.o
	