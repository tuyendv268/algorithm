#include<iostream>
using namespace std;
const int NM=31;
int m, n, k, count = 0;
int g[NM+1][NM+1];
int mark[NM+1], x[NM+1];

void input(){
    int tmp_1, tmp_2;
    cin>>n>>k>>m;
    for(int i = 0; i < m; i++){
        cin>>tmp_1>>tmp_2;
        g[tmp_1][tmp_2] = 1;
        g[tmp_2][tmp_1] = 1;
    }
    for(int i = 0; i <= n; i++){
        mark[i] = 0;
    }
}

void solve(int a){
    for(int i=1; i <= n; i++){
        if(a== 0 || (mark[i] == 0 && g[x[a-1]][i] == 1)){
            mark[i] = 1;
            x[a] = i;

            if(a == k){
                count+=1;
            }else{
                solve(a+1);
            }
            mark[i] = 0;
        }
    }
}

int main(){
    input();
    solve(0);
    cout<<count/2<<endl;

    return 0;
}