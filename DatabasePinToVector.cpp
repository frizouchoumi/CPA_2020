#include "DatabasePinToVector.h"
using namespace std;




string DatabasePinToVector::array_to_string( char* buffer, std::size_t size) 
{ 
    std::ostringstream oss; 
  
    // Afficher en hexadécimal et en majuscule 
    oss << std::hex << std::uppercase; 
    oss << std::setfill('0');
  
    // Injecter tous les caractères sous forme d'entiers dans le flux 
    for (std::size_t i = 0; i < size; ++i) 
    { 
        
        // Séparer chaque octet par un espace 
        if (i != 0) {
            oss << ' '; }

        // Afficher sa valeur hexadécimale précédée de "0x" 
        // setw(2) permet de forcer l'affichage à 2 caractères 


        oss <<  std::setw(2) << static_cast< uint16_t>(buffer[i]); 
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

DatabasePinToVector::DatabasePinToVector(string argv, string type){

    string database = argv;
    char num;
    int length ;
    char * buffer;
 
    ifstream monFlux(database +type, std::ios::in | std::ios::binary);
    /*std::ifstream monFlux(argv[1]+ "psq",ios::in |ios::binary);*/
   
    if (!monFlux.is_open()){
        cout<< " pas ouvert" << endl;
    }
    
    else {
    // Fonction qui était censé permettre de print la base de donnée sous forme normal
  /*  string ligne;
    int x;
    std::vector<string> monFluxte;
    while(getline(monFlux,ligne)){
        
    monFluxte.push_back(ligne);
    std::cout << monFluxte[x-1] << std::endl;
    std::cout << "taille de la Monflux " << monFluxte.size() << std::endl;
    x++;
    }*/
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
   // cout <<"ok" << endl;
    int i = 0;
    vector<string> sequence;
    istringstream iss(a); 
    string mot; 
    while ( std::getline( iss, mot, ' ' ) ) 
    { 
        if (mot.size() >> 2) {
            sequence.push_back(mot.substr(2,3));
        i++; 
        }
        else 
        sequence.push_back(mot);
        
    } 
    // ICI Sequence qui est un vecteur qui a comme element : ( 00,00,00,04 ... F9 ...)
   // int sizevect = sequence.size();
   //for (int j=0 ;j<sizevect; j++){
   // cout << sequence[j] << " "<< endl;
  //  }
    // Libérer la mémoire une foMonflux le traitement terminé
    delete[] buffer;
    databaseVector= sequence;

    }
}


vector<std::string> DatabasePinToVector::getDatabaseVector(){
    return databaseVector;
}