#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int isConnectedBFS(const vector<vector<int>>&adj,int s,int t){
    int c=0;
    if(s==t)
        return c;

    //to make a boolean vector of size same as adj all of values as false
    vector<bool> visited(adj.size(),false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        c++;

        for(int adjacent:adj[node]){
            if(adjacent == t){
                return c;
            }

            if(!visited[adjacent]){
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }

    return -1;
}

int main(){
    int nummNodes = 10;
    vector<vector<int>> adj(nummNodes);

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

    cout<<isConnectedBFS(adj,s,t)<<endl;
}