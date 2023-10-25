#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();

    // Method 1 
	// for(int num: b){
	// 	a.push_back(num);
	// }
	
	// for(int i=n; i<a.size(); i++){
	// 	int j = i-1;
	// 	int key = a[i];
	// 	while(j>=0 && a[j]>key){
	// 		a[j+1] = a[j];
	// 		j--;
	// 	}
	// 	a[j+1]=key;
	// }

	// for(int k=0; k<m; k++){
	// 	b[k]=a[k+n];
	// }

    // a.erase(a.begin()+n, a.end());

    //Method 2
    int i=n-1, j=0;
	while(i>=0 && j<m){
		if(a[i]>b[j]){
			swap(a[i], b[j]);
			i--;
			j++;
		}else{
			break;
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

int main(){
    vector<long long> a {1, 8, 8};
    vector<long long> b {2, 3, 4, 5};
    mergeTwoSortedArraysWithoutExtraSpace(a, b);
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int j: b){
        cout<<j<<" ";
    }
}