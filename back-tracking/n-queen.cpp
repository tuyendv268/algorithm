#include<iostream>
using namespace std;
int board[8][8];
int n = 8, count = 0;

bool check(int i, int k){
    for(int j = 0; j < k; j++){
        if(board[i][j] == 1) return false;
    }
    int y = i-1, x = k-1;
    while(y >= 0 && x >= 0){
        if(board[y][x] == 1) return false;
        x--;
        y--;
    }
    y = i+1; x = k-1;
    while(y < n && x >=0){
        if(board[y][x] == 1) return false;
        y++;
        x--;
    }

}

void print(){
    for(int i =0 ;i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(int k){
    if(k == n){
        // print solution
        count++;
        print();
        return;
    }

    for(int i = 0; i < n; i++){
        if(board[i][k] == 0 && check(i, k)){
            board[i][k] = 1;
            solve(k+1);
            board[i][k] = 0;
        }
    }
}

int main(){
    solve(0);
    cout<<count;
    return 0;
}