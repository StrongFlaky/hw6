#include <string>
#include <algorithm>
#include "BWT.h"
#include <vector>
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    string btwFinal;
    vector<string> bwtBegin;
    int length = s.size();
    for(int i = 0; i < length; i++){
        string currentRotation = s.substr(i, length) + s.substr(0, i);
        bwtBegin.push_back(currentRotation);
    }
    sort(bwtBegin.begin(), bwtBegin.end());
    for(int i = 0; i < length; i++){
        btwFinal = btwFinal + bwtBegin[i].substr(length-1);
    }
    return btwFinal;
}
