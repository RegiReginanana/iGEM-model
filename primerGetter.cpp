

#include <iostream>
#include <fstream>

using namespace std;

string _dna;
string _tar;
string _res = "DNA strand is too short.";

const int MAXI = 40; //setting primer length

void ParseTargetDNA () {
    ifstream inFile ("target.dna");

    inFile >> _tar;

    inFile.close();
}

void ParseOriDNA () {
    ifstream inFile ("input.dna");

    inFile >> _dna;

    inFile.close();
}

void ParseIn () {

    ParseTargetDNA();
    ParseOriDNA();
}

string GenRes (int ini) {
    string res = "";
    int bit;

    bit = ini - MAXI;

    for (int i = 0; i < MAXI; i++) {
        res += _dna[i + bit];
    }

    res += _tar;

    bit = ini + _tar.size();

    for (int i = 0; i < MAXI; i++) {
        res += _dna[i + bit];
    }

    return res;
}

void Core () {
    bool flag = true;

    if (_dna.length() < 2 * MAXI + 1) {
        return;
    }

    _res = "";

    for (int i = MAXI; i < _dna.length() - MAXI; i++) {
        for (int j = i; j < _tar.length() + i; j++) {
            if (_tar[j - i] != _dna[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            _res = GenRes(i);
        }

        flag = true;
    }
}

void CWriteOut () {
    ofstream outFile("primer.dna");

    outFile << _res;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}