#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(vector<vector<int>> &adj,int s,int t,vector<bool> & visited){
    if(s==t){
        return true;
    }

    visited[s] = true;

    for(int adjacent:adj[s]){
        if(!visited[adjacent]){
            if(dfs(adj,adjacent,t,visited)){
                return true;
            }
        }
    }

    return false;
}

bool isConnectedDFS(vector<vector<int>>&adj,int s,int t){
    vector<bool> visited(adj.size(),false);
    return dfs(adj,s,t,visited);
}

int main(){
    int numNodes = 10;
    vector<vector<int>> adj(numNodes);

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,6);
    addEdge(adj,3,7);
    addEdge(adj,4,7);
    addEdge(adj,4,8);

    int s=1;
    int t=6;
    
    cout<<isConnectedDFS(adj,s,t)<<endl;
}