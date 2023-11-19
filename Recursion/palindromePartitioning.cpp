#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]) 
            return false;
    }
    return true;
}

void helper(int ind, string s, vector<string> temp, vector<vector<string>>& res){
    if(ind==s.length()){
        res.push_back(temp);
        return;
    }

    for(int i=ind; i<s.length(); i++){
        if(isPalindrome(s, ind, i)){
            temp.push_back(s.substr(ind, i-ind+1));
            helper(i+1, s, temp, res);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> temp;
    vector<vector<string>> res;
    helper(0, s, temp, res);
    return res;
}

int main(){
    string s = "ababba";
    vector<vector<string>> res = partition(s);
    for(auto item: res){
        for(string i: item)
            cout<<i<<" ";
        cout<<endl;
    }
}