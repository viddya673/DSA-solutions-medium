#include <iostream>
#include <vector>
using namespace std;

bool wordBreak(string s, vector<string>& wordBreak){
    int n = s.length();
    vector<bool> dp(n, false);
    dp[n] = true;

    for(int i=n-1; i>=0; i--){
        for(auto x: wordBreak){
            if(i+x.size()<=n && s.substr(i, x.size())==x)
                dp[i] = true;
            if(dp[i]==true)
                break;
        }
    }
    return dp[0];
}

int main(){
    string s = "catsandog";
    vector<string> wordDict{"cats","dog","sand","and","cat"};

    cout<<wordBreak(s, wordDict);
}