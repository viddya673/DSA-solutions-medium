#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& heap, int i, int n){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<=n && heap[left]>heap[largest])
        largest = left;
    if(right<=n && heap[right]>heap[largest])
        largest = right;    
    
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify(heap, largest, n);
    }
}

void heapSort(vector<int>& heap, int n){
    for(int i=n; i>0; i--){
        swap(heap[i], heap[1]);
        heapify(heap, 1, i-1);
    }
}

int main(){
    vector<int> heap = {0, 50, 20, 40, 5, 10, 30};
    heapSort(heap, heap.size()-1);

    for(int val: heap)
        cout<<val<<endl;
}