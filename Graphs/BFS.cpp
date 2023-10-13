#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    queue<int> q;
    vector<int> visited(n+1, 0);
    vector<int> res;
    int root=0;
    q.push(root);
    visited[0] = 1;

    // while(!q.empty()){
    //     int curr = q.front();
    //     res.push_back(curr);
    //     q.pop();
        
    //     for(int a: adj[curr]){
    //         if(visited[a]==0){
    //             q.push(a);
    //             visited[a] = 1;
    //         }
    //     }
    // }
    while(!q.empty()){
        int l_size = q.size();

        for(int i=0; i<l_size; i++){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int a: adj[curr]){
                if(visited[a]==0){
                    visited[a]=1;
                    q.push(a);
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> adj{{1,2,3}, {4}, {5}, {}, {}, {}};
    int n = adj.size();
    vector<int> res = bfsTraversal(n, adj);
    for(int r: res){
        cout<<r<<endl;
    }
}