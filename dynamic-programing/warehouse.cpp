#include<iostream>
using namespace std;
const int N_max = 1001;
const int T_max = 1001;
const int D_max = 20;
int a[N_max], t[N_max];
int S[N_max][T_max];
int N, T, D;
void input(){
    cin>>N>>T>>D;
    for(int i = 1; i<= N; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= N; i++){
        cin>>t[i];
    }
}
void solve(){
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= T; j++){
            S[i][j] = 0;
        }
    }
    
    S[1][t[1]] = a[1];
    for(int i = 2; i <= N; i++){
        for(int k = 0; k <= T; k++){
            if(k == t[i]){
                S[i][k] = a[i];
            }else{
                S[i][k] = 0;
            }
            for(int j = i - D; j < i; j ++){
                if(j >= 1 && k - t[i] >= 0){
                    S[i][k] = max(S[i][k], S[j][k-t[i]] + a[i]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= T; j++){
            ans = max(ans, S[i][j]);
        }
    }
    cout<<ans;
}

int main(){
    input();
    solve();
    return 0;
}