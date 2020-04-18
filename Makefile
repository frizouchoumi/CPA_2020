all : DatabasePinTovector.o pinAnalyser.o psqAnalyser.o
	g++ DatabasePinTovector.o pinAnalyser.o psqAnalyser.o main.cpp -o main
DatabasePinTovector.o: DatabasePinTovector.cpp  DatabasePinTovector.h
	g++ -c DatabasePinTovector.cpp
pinAnalyser.o : pinAnalyser.cpp pinAnalyser.h
	g++ -c pinAnalyser.cpp
psqAnalyser.o : psqAnalyser.cpp psqAnalyser.h
	g++ -c psqAnalyser.cpp
clean : 
	del *.o
	