#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void appendZeros(int i, int j, int r_len, int c_len, vector<vector<int>>& matrix){
        for(int k=0; k<c_len; k++){
            matrix[i][k] = 0;
        }
        for(int k=0; k<r_len; k++){
            matrix[k][j] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int c_len = matrix[0].size();
        int r_len = matrix.size();
        set<pair<int, int>> s;

        for(int i=0; i<r_len; i++){
            for(int j=0; j<c_len; j++){
                if(matrix[i][j] == 0){
                    s.insert({i, j});
                }
            }
        }
        for (auto pair: s){
            appendZeros(pair.first, pair.second, r_len, c_len, matrix);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix{{1,1,1}, {1,0,1}, {1,1,1}};
    s.setZeroes(matrix);
    for(auto row: matrix){
        for(int elem: row){
            cout<<elem<<",";
        }
        cout<<endl;
    }
}