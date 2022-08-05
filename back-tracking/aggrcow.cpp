#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000001

const long long NM = 100001;
const long long CM = 100001;
long long N, C, res = -1;
long long x[NM];

void input(){
    scanf("%ld %ld", &N, &C);
    for(long long i=0; i < N; i++){
        scanf("%ld", &x[i]);
    }
    sort(x,x+N);
}
void solve(long long left, long long right){
    if(left > right) return;
    long long mid = (left+right)/2;

    // ddeem so bof dduojc dat vao chuong voiw khoang cachh mid
    long long ni = x[0];
    long long cnt = 1;
    for(long long i = 1; i < N; i++){
        if(x[i] - ni >= mid){
            ni = x[i];
            cnt++;
        }
    }
    if(cnt < C){
        solve(left, mid-1);
    }else{
        res = mid;
        solve(mid+1, right);
    }
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        input();
        solve(0, MAX);
        cout<<res<<endl;
    }
}