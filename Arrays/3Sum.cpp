#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if (sum==0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        for (auto triplets: s){
            result.push_back(triplets);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(nums);

    for(auto each_vect: result){
        for(int num: each_vect){
            cout<<num<<",";
        }
        cout<<endl;
    }
    
}