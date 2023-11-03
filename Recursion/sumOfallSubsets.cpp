#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(int i, int n, int sum, vector<int>& res, vector<int> nums){
	if(i==n){
		res.push_back(sum);
		return;
	}

	//take
	sum += nums[i];
	helper(i+1, n, sum, res, nums);
	sum -= nums[i];
	
	//not take
	helper(i+1, n, sum, res, nums);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> res;
	int n = num.size();
	helper(0, n, 0, res, num);
	sort(res.begin(), res.end());
	return res;	
}

int main(){
    vector<int> nums{1, 2, 3};
    vector<int> res = subsetSum(nums);
    for(int i: res)
        cout<<i<<endl;
}