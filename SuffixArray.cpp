#include <string>
#include <vector>
#include "SuffixArray.h"
#include <unordered_map> 
#include <algorithm>
using namespace std;

/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    
    vector<string> arrayKey;
    vector<unsigned int> arrayMap;
    int length = s.size();
    for(int i = 0; i < length; i++){
        arrayKey.push_back(s.substr(i, length));
        arrayMap.push_back(i);
    }
    auto compare = [&](int previous, int next){
        if(arrayKey.at(previous) > arrayKey.at(next)){
            return false;
        }
        return true;
    };
    std::sort(arrayMap.begin(), arrayMap.end(), compare);
    return arrayMap;
}
