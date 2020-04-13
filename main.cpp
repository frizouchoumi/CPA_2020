#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

std::string array_to_string( char* buffer, std::size_t size) 
{ 
    std::ostringstream oss; 
  
    // Afficher en hexadécimal et en majuscule 
    oss << std::hex << std::uppercase; 
    oss << std::setfill('0');
  
    // Injecter tous les caractères sous forme d'entiers dans le flux 
    for (std::size_t i = 0; i < size; ++i) 
    { 
        // Séparer chaque octet par un espace 
        if (i != 0) 
            oss << ' '; 
  
        // Afficher sa valeur hexadécimale précédée de "0x" 
        // setw(2) permet de forcer l'affichage à 2 caractères 
        oss <<  std::setw(2) << static_cast<int>(buffer[i]); 
    } 
  
    return oss.str(); 
}

/*void printInBinary(int num) 
{ 
    int n = CHAR_BIT*sizeof(num); 
    stack<bool> s; 
    for (int i=1; i<=n; i++) 
    { 
        s.push(num%2); 
        num = num/2;  
    }      
    for (int i=1; i<=n; i++) 
    { 
        cout << setbase(16) <<s.top()<< endl ; 
        s.pop(); 
          
        // Put a space after every byte.  
        if (i % CHAR_BIT == 0) 
        cout << " ";  
    } 
} */

int main(int argc, char* argv[]){
    string database;
    char num;

    int length;
    char * buffer;
 
  
 
 
    if (argc < 3) {
        std::cout << "Veuillez inclure le fichier prot et la database" << std::endl;
        
    }
    

    else if (argc=3)
    {
        
        database = argv[2];
        std::cout << "Il y a bien les 3 fichiers  " << database << " et "<< argv[1]<< std::endl;
        string test = database + ".psq";
        cout << test << endl;
    }
    
    /*std::string ligne;*/
    
    ifstream monFlux(database +".psq", std::ios::in | std::ios::binary);
    /*std::ifstream monFlux(argv[1]+ "psq",ios::in |ios::binary);*/
   
    if (!monFlux.is_open()){
        cout<< " pas ouvert" << endl;
    }
    
    else {
    // Obtenir la taille du fichier
    monFlux.seekg(0, ios::end);
    length = monFlux.tellg();
    monFlux.seekg(0, ios::beg);
 
    // Allouer de la mémoire pour le fichier
    buffer = new char [length];
 
    // Ecrire les données en mémoire
    monFlux.read (buffer,length);
    monFlux.close();
    
    // UtilMonflux les données ici
    string a =array_to_string(buffer, length) ;
    cout <<a << endl;
    // Libérer la mémoire une foMonflux le traitement terminé
    delete[] buffer;
        
    }
    
    
    
    
    
    
    /*monFlux.get(num);
        cout << "Le premier bail" << setbase(16) << num << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*std::vector<std::string> Monfluxt;
    /*int i =0;
    char* buffer = new char(5);
    if (monFlux.read(buffer,5))
    {
       for (int j =0 ; j<=4 ;j++)
        cout <<"voici le char  "<< buffer[j] << endl;
    }



    
 

   /* getline(monFlux,ligne);*/
    
   /* while(getline(monFlux,ligne)){
        
    Monflux.push_back(ligne);
    std::cout << Monfluxte[i] << std::endl;
    std::cout << "taille de la Monflux " << Monflux.size() << std::endl;
    i++;
    
    }*/
    

    
    



    return 0;
}