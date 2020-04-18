#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
class psqAnalyser {
    private :
    vector<char> sequenceProt;
    vector<int> sequenceLenght;
        



    

    public:
    
        psqAnalyser(vector<string>const& sequencePsq, string argv, vector<int>const& sequenceOffset);
        vector<char> sequenceAcquisition(string argv);
        ~psqAnalyser();
        vector<int> sequenceOffsetUse(vector<int> const & sequenceOffset,vector<string>const& sequencePsq);
        

};

