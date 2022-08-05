#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int NM=1000001;
int res = -1, max_length = -1;
int M, N;
int a[NM];
void input(){
    cin >>N>>M;
    for(int i = 0; i < N; i++){
        cin >>a[i];
        max_length = max(max_length, a[i]);
    }
}
int compute(int mid){
    int total = 0, tmp;
    for(int i=0; i < N; i++){
        tmp =  a[i]-mid;
        if(tmp < 0){
            tmp = 0;
        }
        total += tmp;
    }
    return total;
}

int solve(int left, int right){
    
    int mid = (left+right)/2;
    int total = compute(mid);
    if(total == M || right-left == 1){
        return mid;
    }else{
        if(total < M){
            return solve(left, mid);
        }else{
            return solve(mid, right);
        }
    }
}

int main(){
    input();
    cout<<solve(0, max_length);

    return 0;
}