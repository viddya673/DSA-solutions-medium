#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Brute force
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

    //Optimal
    string reverseWords2(string s) {
        string res = "";
        int n = s.size(), i = n - 1, start = n - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--; // Skip trailing spaces
            }

            start = i; // Mark the end of the current word

            while (i >= 0 && s[i] != ' ') {
                i--; // Move to the beginning of the current word
            }

            // Extract the current word and append it to the result
            string curr = s.substr(i + 1, start - i);
            if (!curr.empty()) {
                res += (res.empty() ? "" : " ") + curr;
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    string str = "a good   example";
    cout<<s.reverseWords(str)<<endl;
    cout<<s.reverseWords2(str);
}