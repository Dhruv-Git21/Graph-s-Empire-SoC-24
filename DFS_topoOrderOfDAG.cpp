#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<vector<int>> &graph,stack<int>&stack,vector<bool> &visited){
    visited[v] = true;

    for(int i:graph[v]){
        if(!visited[i]){
            dfs(i,graph,stack,visited);
        }
    }

    stack.push(v);
}

vector<int> topoOrder(vector<vector<int>>&graph){
    int n= graph.size();

    stack<int> stack;
    vector<bool> visited(n,false);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,graph,stack,visited);
        }
    }

    vector<int> topoOrder;
    while(!stack.empty()){
        topoOrder.push_back(stack.top());
        stack.pop();
    }

    return topoOrder;
}

int main(){
    vector<vector<int>> graph={{1,2},{2,3},{3},{}};
    vector<int> topo = topoOrder(graph);

    for(int i:topo){
        cout<<i<<" ";
    }
    cout<<endl;
}