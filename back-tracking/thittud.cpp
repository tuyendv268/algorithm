#include<bits\stdc++.h>
#include<iostream>
using namespace std;
const int NM = 1000001;
int n;
int a[NM], res = -1, cur_len = 1;
void input(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
}
void solve(){
    int tmp;
    for(int i = 1; i<= n-1; i++){
        tmp = i;
        while(a[tmp+1] > a[tmp]){
            // cout<<a[tmp] <<"-"<<a[tmp+1]<<endl;
            tmp++;
            cur_len++;
        }
        res = max(res, cur_len);
        cur_len = 1;
        i = tmp;
    }
}

int main(){
    input();
    solve();
    cout<<res;

    return 0;
}