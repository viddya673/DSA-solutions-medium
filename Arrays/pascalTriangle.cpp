#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++){
            vector<int> row(i+1, 1);
            for(int j=1; j<i; j++){
                row[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for(auto item: res){
        for(int i: item)
            cout<<i<<" ";
        cout<<endl;
    }
}