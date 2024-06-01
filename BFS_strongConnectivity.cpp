#include<bits/stdc++.h>
using namespace std;

void bfs(int start,vector<vector<int>> &graph,vector<bool> &visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:graph[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool isStronglyConnected(vector<vector<int>> &graph){
    int n=graph.size();

    vector<bool> visited(n,false);
    bfs(0,graph,visited);

    for(bool v:visited){
        if(!v){
            return false;
        }
    }

    vector<vector<int>> reversedGraph(n);
    for(int u=0;u<n;u++){
        for(int v:graph[u]){
            reversedGraph[v].push_back(u);
        }
    }

    fill(visited.begin(),visited.end(),false);
    bfs(0,reversedGraph,visited);

    for(bool v:visited){
        if(!v){
            return false;
        }
    }

    return true;
}

int main(){
    vector<vector<int>> graph={{0,1},{1,2},{2,3},{3,0}};
    cout<<isStronglyConnected(graph)<<endl;
}