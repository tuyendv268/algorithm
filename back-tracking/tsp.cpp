#include<iostream>
using namespace std;
const int NM = 21;
int m, n, res=-1, sum = 0;
int c[NM][NM], mark[NM];
int S[NM];
void input(){
    int tmp_1, tmp_2;
    cin >>n>>m;
    for(int i = 0; i < m; i++){
        cin>>tmp_1>>tmp_2;
        cin>>c[tmp_1][tmp_2];
    }
    for(int i =0; i <= n; i++){
        mark[i]= 0;
    }
}

void solve(int k){
    for(int i = 2; i <= n; i++){
        if(mark[i] == 0 && c[S[k-1]][i] != 0){
            mark[i] = 1;
            sum += c[S[k-1]][i];
            S[k] = i;
            if(k == n){
                if(c[S[n]][1] != 0) res = max(res, sum + c[S[n]][1]);
            }else{
                solve(k+1);
            }
            mark[i] = 0;
            sum -= c[S[k-1]][i];
        }
    }
}

int main(){
    input();
    mark[1] = 1;
    S[1] = 1;
    solve(2);
    cout<<res;

    return 0;
}