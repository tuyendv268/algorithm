#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
vector<vector<int>> graph;
map<pair<int, int>, int> weight;
int dist[MAX];

void input(){
    int u, v,w;
    cin>>n;
    graph.resize(n+1);
    for(int i=1; i < n; i++){
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        weight.insert({{u, v}, w});
        weight.insert({{v, u}, w});
    }
    
    for(int i = 1; i <= n; i++){
        dist[i] = -1;
    }
}

int dfs(){
    stack<int> s;
    int u = 1;
    
    dist[u] = 0;
    s.push(u);
    while(!s.empty()){
        int v = s.top(); s.pop();
        for(int child: graph[v]){
            if(dist[child] == -1){
                // dist[child] = dist[v] + 1;
                dist[child] = dist[v] + weight[{v,child}];

                s.push(child);
            }
        }
    }
    
    int max_path = -1, index;
    for(int i= 1; i <= n; i++){
        if(max_path<dist[i]){
            max_path = dist[i];
            index = i;
        }
    }
    return index;
}

void solve(){
    int v = dfs(), u = 1;
    // cout<<"v: "<<v<<endl;
    for(int i = 1; i <= n; i++){
        dist[i] = -1;
    }
        
    stack<int> s;
    s.push(v);
    dist[v] = 0;
    // cout<<"dfs"<<endl;
    while(!s.empty()){
        int u_tmp = s.top(); s.pop();
        // cout<<u_tmp<<endl;
        for(int v_tmp:graph[u_tmp]){
            if(dist[v_tmp] == -1){
                dist[v_tmp] = dist[u_tmp] + weight[{u_tmp,v_tmp}];
                s.push(v_tmp);
            }
        }
    }
    int max_weight = -1;
    for(int i= 1; i <= n; i++){
        if(max_weight<dist[i]){
            max_weight = dist[i];
        }
    }
    cout<<max_weight<<endl;
}

int main(){
    input();
    solve();
    
    return 0;
}