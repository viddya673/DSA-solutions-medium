#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0, start=0, maxLen=0;
        unordered_map<char, int> mp;

        for(int end=0; end<s.length(); end++){
            mp[s[end]]++;
            maxFreq = max(maxFreq, mp[s[end]]);

            if(end-start+1-maxFreq > k){
                mp[s[start]]--;
                start++;
            }else{
                maxLen = max(maxLen, end-start+1);
            }
        }
        return maxLen;
    }
};

int main(){
    string str = "AABEAFAABEAFA";
    Solution s;
    cout<<s.characterReplacement(str, 1);
}