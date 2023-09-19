#include <iostream>
#include <queue>
using namespace std;

/*Genral Idea of how priority queue can help in finding kth largest element*/
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         for(int x: nums)
//             pq.push(x);

//         int i=0;
//         while(i<k-1){
//             pq.pop();
//             i++;
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> p(nums.begin(), nums.begin()+k);
        
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};

int main(){
    vector<int> nums{20, 10, 60, 30, 50, 40};
    Solution s;
    cout<<s.findKthLargest(nums, 3);
}