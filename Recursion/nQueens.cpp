#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
    bool isValid(int row, int col, int n, vector<string> board) {
        int drow = row;
        int dcol = col;

        //check left upper diagonal
        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q') return false;
        }

        //check left horizonatal
        row = drow;
        col = dcol;
        while(col>=0){
            if(board[row][col--]=='Q') return false;
        }

        //check left lower diagonal
        row = drow;
        col = dcol;
        while(row<n && col>=0){
            if(board[row++][col--]=='Q') return false;
        }
        return true;
    }

    void solver(int col, vector<string>& board, vector<vector<string>>& res, int n) {
        if(col==n){
            res.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isValid(row, col, n, board)){
                board[row][col] = 'Q';
                solver(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> res;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
          board[i] = s;
        }
        solver(0, board, res, n);
        return res;
    }
};

/* Slightly more optimal */
class Solution2 {
    public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};

int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution1 s1;
  vector < vector < string >> ans = s1.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}