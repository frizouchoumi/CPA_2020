#include "psqAnalyser.h"
using namespace std;
    psqAnalyser::psqAnalyser(vector<string>const& sequencePsq, string argv,vector<int>const& sequenceOffset, int residu ){
        sequenceProt = sequenceAcquisition(argv); 
        sequenceLenght = sequenceOffsetUse(sequenceOffset,sequencePsq,residu);
        //std::cout << sequenceProt.size() << endl;
        //std::cout <<sequenceProt[1]<< endl;
       // std::cout << sequenceOffset[4] << "     " << sequenceOffset[1] << endl ;
       // std::cout << sequenceLenght[0] << "ou" << sequenceLenght [1] << sequenceLenght[2] << sequenceLenght[3] << endl ;
        //cout << sequenceLenght.size(); 
        //SAVOIR QUE LA SEQUENCE ENREGISTRER SOUS FORME DE LETTRE A UNE LETTRE EN MOINS ( caractère /n pas coder )
        candidateNumber = candidateNumbershearching(sequenceProt,sequenceLenght);
        // std::cout<< " on est là "<< endl ;
        // A cet étape là du constructeur on a normalement les indices de toutes les séquence ayant la même longueur que celle recherché stocker dans candidate number
        //std::cout << candidateNumber[0] << endl;
        candidate = candidateShearching(candidateNumber,sequencePsq,sequenceOffset);
        // Ici j'ai un vecteur de vecteur avec tout les candidats : Reste à convertir ce vecteur candidat en vecteur avec des A , B , C , D , E ,F etc puis comparer avec séquence prot et enfin retourner le bon et enfin check le header avec le bon indice et c'est TERMINER <3 
        indicewinner = findIndiceWinner(sequenceProt,candidate ,candidateNumber);


        
    }






// return un vecteur avec la séquence de la prot chercher, on peut retrouver sa taille izi avec size

vector<string> psqAnalyser::sequenceAcquisition(string argv){ 
        ifstream maProtSeq(argv);
        string garbage;
        string mot;
        char seqChar[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string seqString[26] = {"01","02","03","04","05","06","07","08","09","1B","0A","0B","0C","0D","1A","0E","0F","10","11","12","18","13","14","15","16","17"};
       
        vector<string> bail;
        getline(maProtSeq,garbage);
        while(getline(maProtSeq,mot)){
            
            for (int k = 0 ; k < mot.size(); k++){
            int i = 0 ;
            while (i < 26 && mot[k] != seqChar[i]) {
            i++;
            }

            bail.push_back(seqString[i]);
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
vector<int> psqAnalyser::candidateNumbershearching(vector<string> sequenceProt,vector<int> sequenceLenght){
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

vector<vector<string>> psqAnalyser::candidateShearching(vector<int> candidateNumber,vector<string> const& sequencePsq, vector<int> const& sequenceOffset){
    vector<vector<string>> candidate;
    for ( int i = 0 ; i< candidateNumber.size(); i++){
        vector<string> exodia;
        for (int j = sequenceOffset[candidateNumber[i]]; j < (sequenceOffset[candidateNumber[i] +1 ])-1 ; j++){
            exodia.push_back(sequencePsq[j]);
        }
        candidate.push_back(exodia);
    }
    return candidate;
}

int  psqAnalyser::findIndiceWinner(vector<string> sequenceProt,vector<vector<string>> candidate , vector<int> candidateNumber){
    int i = 0;
    while ( i<candidate.size() && candidate[i] != sequenceProt) {
        i++;
    } 
    if (i < candidate.size()) {
        std::cout << "la sequence est "<< endl;
        for (int j = 0 ; j< candidate[i].size(); j++){
          std::cout <<  candidate[i][j];
        }
        std:cout << endl;
        return candidateNumber[i];
         
    }
    else {
        std::cout << " pas de correspondance parfaite"<< endl;
        return 0;
    }
    
}

int psqAnalyser::getIndicewinner(){
    return indicewinner;
}





