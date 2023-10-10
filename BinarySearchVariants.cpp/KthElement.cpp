#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Kth element after merging two sorted arrays*/
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int i=0, j=0;
    vector<int> resultant;
    sort(row1.begin(), row1.end());
    sort(row2.begin(), row2.end());
    while(i<m || j<n){
        if(row1[i]<row2[j]){
            resultant.push_back(row1[i]);
            i++;
            k--;
        }else{
            resultant.push_back(row2[j]);
            j++;
            k--;
        }
        if(k==0)
            return resultant.back();
    }
    return -1;
}

int main(){
    vector<int> v1 {1};
    vector<int> v2 {2};
    cout<<ninjaAndLadoos(v1, v2, 1, 1, 2);
}