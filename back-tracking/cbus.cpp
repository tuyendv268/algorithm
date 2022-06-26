#include<iostream>
using namespace std;
const int NM=11;
int n, res=999999, sum=0;
int passengers=0, min_dist = 999999;
int c[2*NM+1][2*NM+1];
int mark[2*NM + 1], s[2*NM+1];

void input(){
    cin >>n;
    for(int i = 0; i<=2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
    mark[0] = 1;
}
bool check(int a, int i){
    if(passengers == 1) 
        if(i <= n) return false;
    if(c[s[a-1]][i] == 0) return false;
    if(i > n)
        if(!mark[i-n]) return false;
    if(!mark[i]) return true;
    return false;
}

void find_min_distance(){
    for(int i = 0; i <= 2*n; i++){
        for(int j=0; j <= 2*n; j++){
            if(i!=j){
                min_dist = min(min_dist, c[i][j]);
            }
        }
    }
}

void solve(int a){
    for(int i = 1; i <= 2*n; i++){
        if(check(a, i)){
            mark[i] = 1;
            sum += c[s[a-1]][i];
            s[a] = i;
            if(i <= n) passengers += 1;
            else passengers -= 1;
            if(a == 2*n){
                if(c[s[2*n]][0] != 0){
                    res = min(res, sum + c[s[2*n]][0]);
                }
            }else{
                if((sum + (2*n-a)*min_dist) < res){
                    solve(a+1);
                }
            }
            mark[i] = 0;
            sum -= c[s[a-1]][i];
            if(i <= n) passengers -= 1;
            else passengers += 1;
        }
    }
}

void print(){
    cout<<n;
    for(int i = 0; i<=2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cout<< c[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    input();
    s[0] = 0;
    find_min_distance();
    solve(1);
    cout<<res;
}