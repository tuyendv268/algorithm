#include<iostream>
using namespace std;
const long long MAX=1000000;
long long N, M;
long long height[MAX];
long long maxHeight;

void input(){
    cin >> N >> M;
    for(long long i = 0; i < N; i++){
        scanf("%ld",&height[i]);
        maxHeight = max(maxHeight, height[i]);
    }
}

long long compute_total(long long cut){
    long long sum = 0, tmp;
    for(int i = 0; i < N; i++){
        tmp = height[i] - cut;
        if(tmp < 0){
            tmp = 0;
        }
        sum += tmp;
    }
    return sum;
}

long long solve(long long left, long long right){
    long long mid = (left + right)/2;
    long long total = compute_total(mid);
    if(right - left == 1 || total == M){
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
    cout<<solve(0, maxHeight);
    return 0;
}
