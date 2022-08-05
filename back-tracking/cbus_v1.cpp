#include<iostream>
using namespace std;
const int NM = 11;
int n, k, res = INT_MAX, sum = 0;
int dist[2*NM+1][2*NM+1];
int mark[2*NM+1], passengers = 0, min_dist = INT_MAX;
int s[2*NM+1];

void input(){
    cin >>n>>k;
    for(int i=0; i< 2*n+1; i++){
        for(int j = 0; j < 2*n +1; j++){
            cin>>dist[i][j];
            if(i != j){
                min_dist = min(min_dist, dist[i][j]);
            }
        }
    }
    // for(int i=0; i< 2*n+1; i++){
    //     for(int j = 0; j < 2*n +1; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

bool check(int a, int i){
    if(passengers>=k){
        if(i <= n) return false;
        // neu da co du k khach thi khong don nua
    }
    if(i>n){
        if(mark[i-n] == 0) return false;
        // neu di tra khach ma lai chua don khach thif return false
    }
    if(dist[s[a-1]][i] == 0) return false; // neu khong co duong di thi return false
    
    if(!mark[i]) return true; // neu chua den thi return true
    
    return false;
}

void solve(int a){
    for(int i = 1; i < 2*n +1; i++){
        if(check(a, i)){
            mark[i] = 1;
            s[a]=i;
            sum += dist[s[a-1]][i];
            
            if(i<=n) 
                passengers+=1;
            else
                passengers-=1;
            
            if(a == 2*n){
                // get result
                if(dist[s[2*n]][0] != 0){
                    res = min(res, sum+dist[s[2*n]][0]);
                }
            }else{
                if(res > ((2*n-a)*min_dist + sum))
                    solve(a+1);
            }
            
            mark[i] = 0;
            sum -= dist[s[a-1]][i];
            
            if(i<=n)
                passengers-=1;
            else
                passengers+=1;
        }
    }
}

int main(){
    input();
    solve(1);
    cout<<res;
    return 0;
}
