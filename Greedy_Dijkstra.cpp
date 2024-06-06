#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> Dijkstra(Graph &graph,int start){
    int n=graph.size();
    vector<int> dist(n,INT_MAX);
    dist[start] = 0;

    priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int currDist = pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(currDist>dist[u]){
            continue;

        }

        for(Edge&edge : graph[u]){
            int v=edge.first;
            int weight = edge.second;

            if(dist[u]+weight<dist[v]){
                dist[v] = dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;
}

int main(){
    int n ,m ;
    cout<<"enter nodes and edges"<<endl;
    cin>>n>>m;

    Graph graph(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int start;
    cin>>start;

    vector<int> distances = Dijkstra(graph,start);
    for(int i=0;i<distances.size();i++){
        cout<<distances[i]<<" ";
    }
    cout<<endl;
}