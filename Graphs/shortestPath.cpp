#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<list<int>> adj, int v, int src, int dest){
    vector<int> dist(v+1);
    dist[1] = 0;
    vector<int> pred(v+1);
    vector<bool> visited(v+1, false);

    for(int i=src; i<=v; i++){
        for(auto n: adj[i]){
            if(!visited[n]){
                visited[n] = true;
                dist[n] = dist[i]+1;
                pred[n] = i;
            }
            if(n==dest)
                break;
        }
    }

    vector<int> res;
    int j=dest;
    res.push_back(j);
    while(res.size()<=dist[dest]){
        j=pred[j];
        res.push_back(j);
    }
    reverse(res.begin(), res.end());
    return res;
}

void addVertices(vector<list<int>>& adj, int src, int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int main(){
    int v = 6;
    vector<list<int>> adj(v+1);
    addVertices(adj, 1, 2);
    addVertices(adj, 1, 3);
    addVertices(adj, 1, 5);
    addVertices(adj, 2, 5);
    addVertices(adj, 3, 4);
    addVertices(adj, 4, 5);
    addVertices(adj, 4, 6);
    addVertices(adj, 5, 6);
    
    // for(int i=1; i<=v; i++){
    //     list<int>::iterator itr = adj[i].begin();
    //     cout<<"vertex "<<i<<":";
    //     for(auto neighbour: adj[i]){
    //         cout<<neighbour<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> res = shortestPath(adj, v, 1, 6);
    for(int r: res)
        cout<<r<<endl;
}