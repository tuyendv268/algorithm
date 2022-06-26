#include<iostream>
using namespace std;
int n, K, Q, route = 0;
int d[11], mark[11], S[11];
void input(){
    cin >>n>>K>>Q;
    for(int i = 1; i <= n; i++){
        cin>>d[i];
    }
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
}

bool check(int i){
    if(mark[i] == 0){
        return true;
    }
    return false;
}

void solve(int k, int a, int sum){
    for(int i = 1; i <= n; i++){
        if(check(i)){
            if(sum + d[i] > Q){
                cout<<endl;
                solve(k+1, a, 0);
            }else{
                S[a] = i;
                sum += d[S[a]];
                mark[i] = 1;
                if(a == n){
                    if(sum <= Q){
                        route += 1;
                        // for(int tm = 1; tm<=n;tm++){
                        //     cout<<S[tm]<<" ";
                        // }
                        // cout<<endl;
                    }
                }else{
                    solve(k, a+1, sum);
                }
                sum -= d[S[a]];
                mark[i] = 0;
            }
        }
    }
}

int main(){
    input();
    solve(1, 1, 0);
    long x = (long)(route/2);
    cout<<x%((long)1e9+7)<<endl;
    return 0;
}