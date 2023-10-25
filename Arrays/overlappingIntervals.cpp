#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	
	if (n <= 1) {
        return arr;
    }

	vector<vector<int>> res;
	res.push_back(arr[0]);

	for(int i=1; i<n; i++){
		int m = res.size()-1;
		if(arr[i][0]>=res[m][0] && arr[i][0]<=res[m][1]){
			res[m]={min(arr[i][0],res[m][0]), max(arr[i][1],res[m][1])};
		}else{
			res.push_back(arr[i]);
		}
	}
	return res;
}

int main(){
    vector<vector<int>> arr = {{1,2}, {2,4}, {3,5}, {6,7}};
    vector<vector<int>> res = mergeOverlappingIntervals(arr);
    for(auto vect: res){
        cout<<vect[0]<<" "<<vect[1]<<endl;
    }
}