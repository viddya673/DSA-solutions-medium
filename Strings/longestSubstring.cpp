#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0, start = 0;
        set<char> charSet;

        for(int i=0; i<n; i++){
            if(charSet.count(s[i])==0){
                maxLength = max(maxLength, i-start+1);
                charSet.insert(s[i]);
            }else{
                while(charSet.count(s[i])){
                    charSet.erase(s[start]);
                    start++;
                }
                charSet.insert(s[i]);
            }
        }
        return maxLength;
    }
};

int main(){
    Solution s;
    string str = "abcabcbb";
    cout<<s.lengthOfLongestSubstring(str);
    return 0;
}