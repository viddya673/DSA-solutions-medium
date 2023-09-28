#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for(int num: nums){
            freq_map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto item: freq_map){

            if(pq.size()==k){
                if(pq.top().first < item.second){
                    pq.pop();
                    pq.push({item.second, item.first});
                }
            }else{
                pq.push({item.second, item.first});
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    vector<int> res = s.topKFrequent(nums, 2);
    for(int r: res)
        cout<<r<<endl;
}