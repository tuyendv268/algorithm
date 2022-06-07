#include<iostream>
using namespace std;
int m = 15,n = 5, sum = 0;
int x[6], m0;

void print(){
    for(int i = 1; i <6; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void solve(int k){
    if(k == n){
        x[k] = m0;
        // print solution
        print();
        return;
    }
    m0 = m - sum - (n-k);
    for(int i = 1; i <= m0; i++){
        sum += i;
        x[k] = i;
        solve(k+1);

        sum -= i;
    }
}

int main(){
    solve(1);

    return 0;
}