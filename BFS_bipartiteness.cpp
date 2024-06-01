#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph){
    int n=graph.size();
    vector<int> color(n,-1);

    auto bfs=[&](int start){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v:graph[u]){
                if(color[v] = -1){
                    color[v]=1-color[u];
                    q.push(v);
                }else if(color[v] == color[u]){
                    return false;
                }
            }
        }
        return true;
    };

    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!bfs(i)){
                return false;
            }
        }
    }

    return true;
}

int main(){
    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    cout<<isBipartite(graph)<<endl;
}