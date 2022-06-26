#include<iostream>
using namespace std;
int n, cnt = 0;
int X[7], mark[10]= {0};
int compute(){
    return X[0]*100+X[1]*10+X[2] - (X[6]*100 + 62) + X[3]*1000+X[4]*100+X[5]*10+X[2];
}

void solve(int a){
    for(int i = 1; i <= 9; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            X[a] = i;
            if(a == 6){
                if(compute() == n){
                    cnt++;
                }
            }else{
                solve(a + 1);
            }
            mark[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    solve(0);
    cout<<cnt;

    return 0;
}