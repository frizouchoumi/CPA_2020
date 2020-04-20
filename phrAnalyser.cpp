#include "phrAnalyser.h"

    phrAnalyser::phrAnalyser(vector<string>const& phrSequence , vector<int>const &  headerOffset, int indiceWinner){
        int i = headerOffset[indiceWinner];
        while (i < headerOffset[indiceWinner +1] && phrSequence[i] != "1A")
        {
            i++;
        }
        string a ;
        if (convStringToBin(phrSequence,1,i+1) < 128 ){
            
            a = convBintoChar(phrSequence,  convStringToBin(phrSequence,1,i+1), i+2);
        }
        else {
            int b = convStringToBin(phrSequence,1,i+1) - 128 ;
            int c = convStringToBin(phrSequence,b,i+2);
            a = convBintoChar(phrSequence,c,i+2+b);

        }
        headerFinish = a ;
        std::cout << " Et son nom est " << endl;
        std::cout << headerFinish << endl;
    }


int phrAnalyser::convStringToBin(vector<string> bin, int Lenght, int where){
    string lol;
    for (int i =0 ; i<Lenght ; i++)
    {
        lol += bin[where +i]; 
    }
    int i_hex = stoi(lol,nullptr,16);
    
    
    return i_hex;
}


string phrAnalyser::convBintoChar(vector<string> bin, int Lenght, int where) {
    string charact;
    for ( int i = 0 ; i<Lenght ;i++)
    {
        int a = stoi(bin[where+i],nullptr,16);
        charact += char(a);
    }
    return charact;
}