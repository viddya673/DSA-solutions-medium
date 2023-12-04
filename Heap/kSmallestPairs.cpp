#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({nums1[0]+nums2[0], {0, 0}});
        visited.insert({0, 0});

        while(k-- && !minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});
            visited.insert({i, j});

            if(i+1<n1 && visited.find({i+1, j})==visited.end()){
                minHeap.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }

            if(j+1<n2 && visited.find({i, j+1})==visited.end()){
                minHeap.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }
        return ans;
    }
};
int main(){
    vector<int> nums1 {1,1,2};
    vector<int> nums2 {1,2,3};
    Solution s;
    vector<vector<int>> ans = s.kSmallestPairs(nums1, nums2, 2);
    for(auto a: ans){
        for(int i: a)
            cout<<i<<" ";
        cout<<endl;
    }
        
}