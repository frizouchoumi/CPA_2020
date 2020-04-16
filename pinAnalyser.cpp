#include "PinAnalyser.h"
using namespace std;
    pinAnalyser::pinAnalyser(vector<string> sequencePin){
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
        residueCount = convStringToBinBigEndian(sequencePin,8,position); //?
        position +=8;
        maximeSequence= convStringToBin(sequencePin,4,position); // int qui prendre la valeur de la plus grande sequence
        position +=8;
        headerOffset = convBinToVect(sequencePin, numberSequence , position); // Vecteur qui reprend la position du header de la protéine numéro 1  dans la variable vector[0]
        position += numberSequence*4;
        sequenceOffset = convBinToVect(sequencePin,numberSequence,position);// Vecteur qui reprend  la position de la séquence de la protéine numéro 1  dans la variable vector[0]




        
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
    for (int i = 0; i<NombreDeProt;i++){
        string lol ="";
        for (int j =0 ; i<4 ; j++)
    {
        lol += bin[where +j]; 
    }

    int i_hex = stoi(lol,nullptr,16);
    vectorPosition[i]= i_hex;
    where += 4;
    }

}