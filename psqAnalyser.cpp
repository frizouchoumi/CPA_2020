#include "psqAnalyser.h"
using namespace std;
    psqAnalyser::psqAnalyser(vector<string>const& sequencePsq, string argv,vector<int>const& sequenceOffset, int residu ){
        sequenceProt = sequenceAcquisition(argv); 
        sequenceLenght = sequenceOffsetUse(sequenceOffset,sequencePsq,residu);
        /*std::cout << sequenceProt.size() << endl;
        std::cout << sequenceOffset[4] << "     " << sequenceOffset[1] << endl ;
        std::cout << sequenceLenght[0] << "ou" << sequenceLenght [1] << sequenceLenght[2] << sequenceLenght[3] << endl ;
        cout << sequenceLenght.size(); */
        //SAVOIR QUE LA SEQUENCE ENREGISTRER SOUS FORME DE LETTRE A UNE LETTRE EN MOINS ( caractère /n pas coder )
        candidateNumber = candidateNumbershearching(sequenceProt,sequenceLenght);
        // std::cout<< " on est là "<< endl ;
        // A cet étape là du constructeur on a normalement les indices de toutes les séquence ayant la même longueur que celle recherché stocker dans candidate number
        std::cout << candidateNumber[1] << endl;




        
    }






// return un vecteur avec la séquence de la prot chercher, on peut retrouver sa taille izi avec size
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
        /*for (int i = 0 ; i < bail.size(); i++){
            std::cout <<bail[i] << endl;
        }*/
        return bail;
    }
// vecteur qui a pour chaque element la taille du vecteur de la séquence 
vector<int> psqAnalyser::sequenceOffsetUse(vector<int> const & sequenceOffset,vector<string>const& sequencePsq, int residu){
    vector<int> sequenceLenght;
    for (int i = 0 ; i< sequenceOffset.size() -1 ; i++){
        
        sequenceLenght.push_back(sequenceOffset[i+1]-sequenceOffset[i]);


    }
    sequenceLenght.push_back((residu)-(sequenceOffset[sequenceOffset.size()-1]));
    return sequenceLenght;

}
// Cherche dans le vecteur sequenceLenght les différents numéro des protéienes ayant une séquence égale à celle rechercher
vector<int> psqAnalyser::candidateNumbershearching(vector<char> sequenceProt,vector<int> sequenceLenght){
    vector <int> candidateNumber;
    for (int i = 0; i < sequenceLenght.size(); i++){
        if (sequenceLenght[i] == sequenceProt.size()+1){
            candidateNumber.push_back(i);
        }
    }
    return candidateNumber;
}

vector<int> psqAnalyser::getCandidateNumber(){
    return candidateNumber;
}




