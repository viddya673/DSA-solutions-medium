#include <bits/stdc++.h> 
bool isPossible(int *arr, int n)
{
    int count=0;
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1])
            count++;

        if(count>1)
            return false;

        if(i>=2 && arr[i]<arr[i-2])
            arr[i] = arr[i-1];
    }
    return true;
}

int main(){
    int arr[] = {-78, -68, -51, -20, 187, -182, 42, 64, 66, 93};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<isPossible(arr, n);
    return 0;
}