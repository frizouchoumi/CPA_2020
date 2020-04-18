#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
#include "DatabasePinToVector.h"
using namespace std;




int main(int argc, char* argv[]) {

  
 
 
    if (argc < 3) {
        std::cout << "Veuillez inclure le fichier prot et la database" << std::endl;
        
    }
    

    else if (argc=3)
    {
        
        string ok = argv[2];
        std::cout << "Il y a bien les 3 fichiers  " << argv[2] << " et "<< argv[1]<< std::endl;
        string test = ok + ".pin";
        cout << test << endl;

       vector<char> sequuenceProt= sequenceAcquisition(argv[1]);


        DatabasePinToVector pinDatabase =DatabasePinToVector(argv[2],".pin");
        DatabasePinToVector phrDatabase =DatabasePinToVector(argv[2],".phr");
        DatabasePinToVector psqDatabase =DatabasePinToVector(argv[2],".psq");
        std::cout <<pinDatabase.getDatabaseVector()[0]<< endl;//


    }
    
    /*std::string ligne;*/
    
    
   

    
    return 0;
        
    }

    vector<char> sequenceAcquisition(string argv){ 
        ifstream maProtSeq(argv);
        string garbage;
        string mot;
        
        vector<char> bail;
        getline(maProtSeq,garbage);
        while(getline(maProtSeq,mot)){
            for (int k = 0 ; k < mot.size(); k++){
            bail.push_back(mot[k]);
            }
        }
        for (int i = 0 ; i < bail.size(); i++){
            std::cout <<bail[i] << endl;
        }
        return bail;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
    
 

    



