#include <iostream>
#include <queue>
using namespace std;

/*Connect N ropes with minimum cost*/
int connectNRopes(vector<int> costs){
    priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());

    while(pq.size()!=1){
        int c1 = pq.top();
        pq.pop();
        int c2 = pq.top();
        pq.pop();
        pq.push(c1+c2);
    }
    return pq.top();
}

int main(){
    vector<int> costs {2, 5, 4, 8, 6, 9};
    cout<<connectNRopes(costs);
}