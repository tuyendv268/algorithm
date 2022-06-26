#include<iostream>
using namespace std;
const int NM = 31;
int n, b, res = -1, sum_a = 0, sum_c = 0;
int a[NM], c[NM], mark[NM];

void input(){
    cin>>n>>b;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
}

void solve(int k){
    if(k == n){
        if(sum_a <= b){
            res = max(res, sum_c);
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            sum_a += a[i];
            sum_c += c[i];
            solve(k + 1);
            mark[i] = 0;
            sum_a -= a[i];
            sum_c -= c[i];
        }
    }
}

int main(){
    input();
    solve(1);
    cout<<res;
    return 0;
}