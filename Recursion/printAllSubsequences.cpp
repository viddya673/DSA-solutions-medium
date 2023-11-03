/* Print all subsequences */
#include <iostream>
#include <vector>
using namespace std;

void allSubsequences(int n, vector<int> nums, vector<int>& temp, vector<vector<int>>& res){
    if(n<0){
        res.push_back(temp);
        return;
    }
    //take
    temp.push_back(nums[n]);
    allSubsequences(n-1, nums, temp, res);
    temp.pop_back();

    //not take
    allSubsequences(n-1, nums, temp, res);
}

int main(){
    vector<int> temp;
    vector<vector<int>> res;
    vector<int> nums {1, 2, 3};
    int n = nums.size();

    allSubsequences(n-1, nums, temp, res);
    for(auto item: res){
        for(int i: item){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}