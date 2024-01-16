#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int n=s.size(), start=0;
        stack<char> stk;
        for(int i=0; i<n; i++){
            if(s[i]=='(')
                stk.push(s[i]);
            else if(stk.top()=='(' && s[i]==')'){
                stk.pop();
                if(stk.empty()){
                    res += s.substr(start+1, i-start-1);
                    start = i+1;
                }
            }else stk.push(s[i]);
        }
        return res;
    }
};

int main(){
    string s="(()())(())(()(()))";
    Solution sol;
    cout<<sol.removeOuterParentheses(s);
}