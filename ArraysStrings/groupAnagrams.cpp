#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> strs_map;
        vector<vector<string>> result;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            strs_map[sortedStr].push_back(str);
        }
        
        for(auto key: strs_map){
            result.push_back(key.second);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = s.groupAnagrams(strs);
    for(auto vect: result){
        for(string str: vect){
            cout<<str<<",";
        }
        cout<<endl;
    }
}