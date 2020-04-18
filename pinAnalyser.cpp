#include "PinAnalyser.h"
using namespace std;
    pinAnalyser::pinAnalyser(vector<string>const& sequencePin){
        //Serie d'étapes afin de decomposer le fichier Pin en ses différentes informations. 
        int position =0;
        versionNumber = convStringToBin(sequencePin,4,position); // version de la database
        position += 4;
        databaseType = convStringToBin(sequencePin,4,position);// int 0 ou 1 qui défini le type de la database
        position +=4;
        titleLenght = convStringToBin(sequencePin,4,position);// int qui reprend l taille du titre
        position += 4;
        title = convBintoChar(sequencePin,titleLenght,position);// String qui reprend le titre
        position += titleLenght;
        timeStamplenght = convStringToBin(sequencePin,4,position); // Int qui reprend la taille du string du temps
        position += 4;
        TimeStamp = convBintoChar(sequencePin,timeStamplenght,position); // String qui reprend les info du temps
        position += timeStamplenght;
        numberSequence =convStringToBin(sequencePin,4,position);  // int qui prend le nombre de sequence
        position +=4;
        std::cout << numberSequence<< endl;
        //residueCount = convStringToBinBigEndian(sequencePin,8,position); //?
        position +=8;
        maximeSequence= convStringToBin(sequencePin,4,position); // int qui prendre la valeur de la plus grande sequence
        position +=8;
        headerOffset = convBinToVect(sequencePin, numberSequence , position); // Vecteur qui reprend la position du header de la protéine numéro 1  dans la variable vector[0]
        position += numberSequence*4; 
        //std::cout <<headerOffset[0] << headerOffset[1] << headerOffset[2]<< headerOffset[3] << endl;
        sequenceOffset = convBinToVect(sequencePin,numberSequence,position);// Vecteur qui reprend  la position de la séquence de la protéine numéro 1  dans la variable vector[0]
       // std::cout <<sequenceOffset[0]<< sequenceOffset[2] << endl;
        position += numberSequence*4;
        residu = convStringToBin(sequencePin,4,position);


        
    }

int pinAnalyser::getVersionNumber(){
    return versionNumber;
  
}
int pinAnalyser::getResidu(){
    return residu;
  
}
int pinAnalyser::getNumberSequence(){
    return numberSequence;
}

vector<int> pinAnalyser::getHeaderOffstet(){
    return headerOffset;
}

vector<int> pinAnalyser::getSequenceOffset(){
    return sequenceOffset;
}




// Le vector Bin est un vecteur du style ('00',00',00','01') : les différentes fonctions ci dessous transforme ces string en des variable hexadecimal ,Ox00000001 par exemple puis directement sous leur forme decimal ,1 dans ce cas ci

int pinAnalyser::convStringToBin(vector<string> bin, int Lenght, int where){
    string lol;
    for (int i =0 ; i<Lenght ; i++)
    {
        lol += bin[where +i]; 
    }
    int i_hex = stoi(lol,nullptr,16);
    
    
    return i_hex;
}

int pinAnalyser::convStringToBinBigEndian(vector<string> bin, int Lenght, int where){
    string lol;
    for (int i =0 ; i<Lenght ; i++)
    {
        lol = bin[where +i] + lol; 
    }
    int i_hex = stoi(lol,nullptr,16);
    
    
    return i_hex;
}

string pinAnalyser::convBintoChar(vector<string> bin, int Lenght, int where) {
    string charact;
    for ( int i = 0 ; i<Lenght ;i++)
    {
        int a = stoi(bin[where+i],nullptr,16);
        charact += char(a);
    }
    return charact;
}
vector<int> pinAnalyser::convBinToVect(vector<string> bin, int NombreDeProt , int where){
    vector<int> vectorPosition;
    
    int compteurDePosition = where;
    

    int j = 0;
    while (j < 4*NombreDeProt) {
        
         string lol = "";
        for (int i =0 ; i<4 ; i++)
        {
        lol += bin[compteurDePosition +j]; 
        j++;   
        }
        int i_hex = stoi(lol,nullptr,16);
                    
        vectorPosition.push_back(i_hex);
        //compteurDePosition += 4;
                
        }
    /*
    for (int i = 0; i<NombreDeProt;i++){
        string lol ="";
        for (int j =0 ; i<4 ; j++)
    {
        lol += bin[where +j]; 
    }

    int i_hex = stoi(lol,nullptr,16);
    vectorPosition.push_back(i_hex);
    where += 4;
    }*/
    return vectorPosition;
}