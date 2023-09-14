#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& heap, int val){
    heap.push_back(val);
    int i = heap.size()-1;

    while(i>1){
        int parent = i/2;
        if(heap[parent]<heap[i]){
            swap(heap[parent], heap[i]);
            i = parent;
        }else{
            break;
        }
    }
}

int main(){
    vector<int> heap = {0, 50, 30, 40, 10, 5, 20, 30};
    insert(heap, 60);

    for(int val: heap)
        cout<<val<<endl;
}