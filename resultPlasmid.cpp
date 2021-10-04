

#include <iostream>
#include <fstream>

using namespace std;

string _tar;
string _pismid;
string _res;

//the DNA sequences of pismid that you wanted to insert the target DNA
const int MAXI = 1;

void ParseTarget () {
    ifstream inFile ("target.in");
    
    inFile >> _tar;
    
    inFile.close();
}

void ParsePismid () {
    ifstream inFile ("pismid.in");
    
    inFile >> _pismid;
    
    inFile.close();
}

void ParseIn () {
    ParsePismid();
    ParseTarget();
}

void Core () {
    for (int i = 0; i < _pismid.length(); i++) {
        if (i == MAXI) {
            _res += _tar;
        }
        _res += _pismid[i];
    }
}

void CWriteOut () {
    ofstream outFile("resultPlasmid");

    outFile << _res;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}