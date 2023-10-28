#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& a, int low,int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int cnt = 0;
    vector<int> res(a.begin(), a.end());

    while(i<=mid && j<=high){
        if(res[i]<=res[j]){
            a[k++] = res[i++]; 
        }else{
            cnt += (mid-i+1);
            a[k++] = res[j++];
        }
    }
    while(i<=mid){
        a[k++] = res[i++];
    }
    while(j<=high){
        a[k++] = res[j++];
    }
    return cnt;
}

int mergeSort(vector<int>& a, int low, int high){
    int cnt=0;
    if (low < high) {
        int mid = (low+high) / 2;
        cnt += mergeSort(a, low, mid);
        cnt += mergeSort(a, mid + 1, high);
        cnt += merge(a, low, mid, high);
    }
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n-1);
}

int main(){
    vector<int> a{5, 3, 2, 1, 4};
    cout<<numberOfInversions(a, a.size());
}