#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
#include "DatabasePinToVector.h"
#include "psqAnalyser.h"
#include "PinAnalyser.h"
using namespace std;



 

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

int main(int argc, char* argv[]) {

  
 
 
    if (argc < 3) {
        std::cout << "Veuillez inclure le fichier prot et la database" << std::endl;
        
    }
    

    else 
    {
        
        string ok = argv[2];
        std::cout << "Il y a bien les 3 fichiers  " << argv[2] << " et "<< argv[1]<< std::endl;
        string test = ok + ".pin";
        cout << test << endl;

       //vector<char> sequuenceProt= sequenceAcquisition(argv[1]);


        DatabasePinToVector pinDatabase(argv[2],".pin");
        DatabasePinToVector phrDatabase(argv[2],".phr");
        DatabasePinToVector psqDatabase(argv[2],".psq");
        pinAnalyser pinAnalyse(pinDatabase.getDatabaseVector());
        

       psqAnalyser psqAnalyse(psqDatabase.getDatabaseVector(), argv[1],pinAnalyse.getSequenceOffset(),pinAnalyse.getResidu());
       std::cout << "wuite du main"<< endl;
       /*for (int i = 0 ; i < psqDatabase.getDatabaseVector().size() ;i++){  
           cout << psqDatabase.getDatabase
           Vector()[i] << endl;

       }*/
       /* for (int i = 0 ; i< pinDatabase.getDatabaseVector().size();i++){
       std::cout <<pinDatabase.getDatabaseVector()[i]<< endl;
        }*/
        //vector<char> protSequence = sequenceAcquisition(argv[1]);

       /* for (int i = 0 ; i < protSequence.size();i ++)
        {
            std::cout << protSequence[i] << endl ;
        }*/


    }
    
    /*std::string ligne;*/
    
    
   

    
    return 0;
        
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
    
 

    



