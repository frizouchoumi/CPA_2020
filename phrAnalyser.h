#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class phrAnalyser {
    private :
    string headerFinish;
        




    

    public:
        
        phrAnalyser(vector<string>const& phrSequence , vector<int>const &  headerOffset, int indiceWinner);
        int convStringToBin(vector<string> bin, int Lenght, int where);
        string convBintoChar(vector<string> bin, int Lenght, int where);
      
};

