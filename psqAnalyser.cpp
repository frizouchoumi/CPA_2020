#include "psqAnalyser.h"
using namespace std;
    psqAnalyser::psqAnalyser(vector<string>const& sequencePsq, string argv,vector<int>const& sequenceOffset ){
        sequenceProt = sequenceAcquisition(argv);
        sequenceLenght;
        




        
    }



vector<char> psqAnalyser::sequenceAcquisition(string argv){ 
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
vector<int> psqAnalyser::sequenceOffsetUse(vector<int> const & sequenceOffset,vector<string>const& sequencePsq){
    vector<int> sequenceLenght;
    for (int i = 0 ; i< sequenceOffset.size -1 ; i++){
        
        sequenceLenght.push_back(sequenceOffset[i+1]-sequenceOffset[i]);


    }
    sequenceLenght.push_back((sequenceOffset[sequenceOffset.size()-1])-sequencePsq.size());

}



// Le vector Bin est un vecteur du style ('00',00',00','01') : les différentes fonctions ci dessous transforme ces string en des variable hexadecimal ,Ox00000001 par exemple puis directement sous leur forme decimal ,1 dans ce cas ci


