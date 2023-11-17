#include <iostream>
#include <vector>
using namespace std;
/* Soroco Hackerrank question:
You have a two-dimensional matrix whose each element is an alphabet in small letters A to Z.
You can traverse this matrix following the below two rules:
1. You can always start at index 0, 0. 
2. From current element i, j, you can either go right i, j+1 or go down i+1, j. 
Now you are given a string of alphabet in small letters A to Z. Write a code that checks whether there is a path that can 
be traversed using above-mentioned rules to create this string. If a path exists, then print the path as a string of characters R
and D where R denotes you took right and D denotes where you took down. Print "NO PATH" if no path exists. Assume that there will 
be either no path or exactly one path possible.
*/

void dfs(int ind, int i, int j, vector<vector<char>> matrix, string target, string& curr, string& path) {
    if (ind == target.size()) {
        return;
    }

    // Check right
    if (j + 1 < matrix[0].size() && matrix[i][j + 1] == target[ind]) {
        path += 'R';
        curr += target[ind];
        dfs(ind + 1, i, j + 1, matrix, target, curr, path);
    }

    // Check down
    if (i + 1 < matrix.size() && matrix[i + 1][j] == target[ind]) {
        path += 'D';
        curr += target[ind];
        dfs(ind + 1, i + 1, j, matrix, target, curr, path);
    }

    if(curr!=target){
        // backtrack
        curr.pop_back();
        path.pop_back();
    }
}

string findPath(vector<vector<char>> matrix, string target) {
    string curr = "";
    string path;
    curr += target[0];
    dfs(1, 0, 0, matrix, target, curr, path);
    if(path.length()==target.length()-1)
        return path;
    return "NO PATH";
}

int main() {
    vector<vector<char>> matrix{
        {'a', 'b', 'j', 'd'},
        {'n', 'j', 'k', 'm'},
        {'e', 'f', 'q', 'z'}};
    string target = "abjfqz";
    cout<<findPath(matrix, target);
    return 0;
}