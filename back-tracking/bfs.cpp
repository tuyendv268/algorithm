#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[101][101];
queue<int> q;
int n, m, u, v,s, visited[101];

void BFS(int s){
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<endl;
        for(int v = 1; v <= n; v++){
            if(visited[v] == 0 && a[u][v] == 1){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    
}


int main(){
    cin>>n>>m>>s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        cin >>u>>v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    BFS(s);
    return 0;
}