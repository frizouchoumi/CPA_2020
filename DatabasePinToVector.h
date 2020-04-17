#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

class DatabasePinToVector {

    private:
    vector<std::string> databaseVector;

    



    public :
    std::string array_to_string( char* buffer, std::size_t size) ;
    DatabasePinToVector(string argv, string type);
    vector<std::string> getDatabaseVector();

   
};