#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
class pinAnalyser {
    private :
        int versionNumber;
        int databaseType;
        int titleLenght;
        std::string title;
        int timeStamplenght;
        std::string TimeStamp;
        int numberSequence;
        int residueCount;
        int maximeSequence;
        vector<int> headerOffset;
        vector<int> sequenceOffset;




    

    public:
        int convStringToBin(vector<string> bin, int j, int x);
        pinAnalyser(vector<string>const& sequencePin);
        ~pinAnalyser();
        string convBintoChar(vector<string> bin, int j , int x);
        int convStringToBinBigEndian(vector<string> bin, int Lenght, int where);
        vector<int> convBinToVect(vector<string> bin, int j , int x);
};

