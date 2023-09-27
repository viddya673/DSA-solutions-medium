#include <iostream>
#include <list>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[++i]!=s[--j])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length(), max_len=INT_MIN;
        string res;
        if(n==0 || n==1)
            return s;

        for(int start=0; start<n; start++){
            for(int j=n-1; j>=start; j--){
                if(s[start]==s[j] && isPalindrome(s, start, j)){
                    if(max_len < j-start+1){
                        max_len = j-start+1;
                        res = s.substr(start, max_len);
                    }
                    break;
                }
            }
        }
        return res;
    }
};


int main(){
    string s = "babad";
    Solution c;
    cout<<c.longestPalindrome(s);
}