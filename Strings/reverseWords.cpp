#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> result;
        int n = s.length();
        string temp = "";

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == ' '){
                if(temp != "") result.push(temp);
                temp = "";
            }
            else {
                temp += ch;
            }
        }
        if (temp!="") result.push(temp);

        string final_res = "";
        while(!result.empty()){
            final_res += result.top();
            result.pop();
            if(!result.empty()) final_res += ' ';
        }
        return final_res;
    }
};

int main(){
    Solution s;
    string str = "a good   example";
    cout<<s.reverseWords(str);
}