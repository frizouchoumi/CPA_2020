#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
class psqAnalyser {
    private :
    vector<string> sequenceProt;
    vector<int> sequenceLenght;
    vector<int> candidateNumber;
    vector<vector<string>> candidate;



    

    public:
    
        psqAnalyser(vector<string>const& sequencePsq, string argv, vector<int>const& sequenceOffset, int residu);
        vector<string> sequenceAcquisition(string argv);
        //~psqAnalyser();
        vector<int> sequenceOffsetUse(vector<int> const & sequenceOffset,vector<string>const& sequencePsq, int residu);
        vector<int> candidateNumbershearching(vector<string> sequenceProt,vector<int> sequenceLenght);
        vector<int> getCandidateNumber();
        vector<vector<string>> candidateShearching(vector<int> candidateNumber,vector<string> const& sequencePsq, vector<int> const& sequenceOffset);

};

