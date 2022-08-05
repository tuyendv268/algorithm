#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int n,m;
vector<vector<int>> graph;
int color[MAX];

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
        color[i] = 0;
    }
}

bool solve(){
    queue<int> s;
    int u = 1;
    color[u] = 1;
    s.push(u);
    
    while(!s.empty()){
        int v = s.front(); s.pop();
        for(int tmp: graph[v]){
            if(color[tmp] == 0){
                if(color[v] == 1){
                    color[tmp] = 2;
                }else if(color[v] == 2){
                    color[tmp] = 1;
                }
                s.push(tmp);
            }else{
                if(color[tmp] == color[v])return false;
            }
        }
    }
    return true;
}

int main(){
    input();
    cout<<solve();
    
    return 0;
}