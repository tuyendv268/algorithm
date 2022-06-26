#include<iostream>
using namespace std;
const int NM=31;
const int BM = 1e6+1;
int n, b;
int a[NM], c[NM], mark[NM];
int res = -1, sum = 0, weight = 0;
void input(){
    cin>>n>>b;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }
    for(int i =1; i <= n; i++){
        mark[i] = 0;
    }
}
void solve(int k){
    if(k == n){
        // in ra ket qua
        if(weight <= b){
            res = max(res, sum);
        }
        return;
    }
    for(int i=1; i <=n ;i++){
        if(mark[i] == 0){
            mark[i] = 1;
            sum += c[i];
            weight += a[i];
            solve(k+1);
            sum -= c[i];
            weight -= a[i];
            mark[i] = 0;
        }
    }
}

int main(){
    input();
    solve(1);
    cout<<res<<endl;
    return 0;
}