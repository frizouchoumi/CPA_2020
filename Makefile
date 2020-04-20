all : DatabasePinTovector.o pinAnalyser.o psqAnalyser.o phrAnalyser.o
	g++ DatabasePinTovector.o pinAnalyser.o psqAnalyser.o phrAnalyser.o main.cpp -o main
DatabasePinTovector.o: DatabasePinTovector.cpp  DatabasePinTovector.h
	g++ -c DatabasePinTovector.cpp
pinAnalyser.o : pinAnalyser.cpp pinAnalyser.h
	g++ -c pinAnalyser.cpp
psqAnalyser.o : psqAnalyser.cpp psqAnalyser.h
	g++ -c psqAnalyser.cpp
phrAnalyser.o : phrAnalyser.cpp phrAnalyser.h
	g++ -c phrAnalyser.cpp
clean : 
	del *.o
	