#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int n, m, cnt = 0;
vector<vector<int>> graph;
bool visited[MAX];

void input(){
    int tmp1, tmp2;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i = 1; i <= m; i++){
        cin>>tmp1>>tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }
}

void explore(int u){
    visited[u] = 1;
    for(int v=0; v<graph[u].size(); v++){
        if(!visited[graph[u][v]]){
            visited[graph[u][v]] = 1;
            explore(graph[u][v]);
        }
    }
}

void solve(){
    for(int i=1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            explore(i);
        }
    }
}

int main(){
    input();
    solve();
    cout<<cnt;
    
    return 0;
}