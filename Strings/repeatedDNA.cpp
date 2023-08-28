#include<iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int maxLength=10, start=0;
        map<string, int> sequenceCount;
        vector<string> result;

        while(start+maxLength <= s.length()){
            string sequence = s.substr(start, maxLength);
            sequenceCount[sequence]++;
            if(sequenceCount[sequence]==2){
                result.push_back(sequence);
            }
            start++;
        }
        return result;
    }
};

int main(){
    Solution s;
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = s.findRepeatedDnaSequences(str);
    for(string r: res){
        cout<<r<<endl;
    }
}