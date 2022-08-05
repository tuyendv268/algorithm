#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int f,s,g,u,d;
int mv[2];
queue<int> q;
int dist[MAX];
int res=-1, cnt = 0;

void input(){
    cin>>f>>s>>g>>u>>d;
    mv[0]=u;
    mv[1]=-d;
    for(int i = 0; i < MAX; i++){
        dist[i] = -1;
    }
}

void solve(int s){
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int j=0; j <=1; j++){
            int next = v + mv[j];
            if(next > 0 && next <= f){
                if(dist[next] == -1){
                    if(next == g){
                        res = dist[v] + 1;
                        return;
                    }else{
                        q.push(next);
                        dist[next] = dist[v] + 1;   
                    }
                }
            }
        }
    }
}

int main(){
    input();
    solve(s);
    if(res == -1){
        cout<<"use the stairs"<<endl;
    }else{
        cout<<res;
    }
    
    return 0;
}