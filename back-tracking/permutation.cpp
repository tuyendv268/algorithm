#include<iostream>

using namespace std;
int arr[] = {5, 6, 7, 8};
int n = 4;
int mark[10],res[10];

void print(){
    for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void solve(int k){
    if(k == n){
        print();
        // print solution
    }
    for(int i = 0; i < n; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            res[k] = i;
            solve(k+1);
            mark[i] = 0;
        }
    }
}


int main(){
    solve(0);

    return 0;
}