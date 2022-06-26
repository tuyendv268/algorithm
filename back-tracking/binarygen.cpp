#include<iostream>
using namespace std;
string S;
int n;


int main(){
    cin >> n;
    cin >>S;

    int i = n -1;
    while(S[i] == '1'){
        i--;
    }

    if(i < 0){
        cout<<"-1"<<endl;
        return 0;
    }else{
        if(i == n - 1){
            S[n-1] = '1';
        }else{
            S[i] = '1';
            for(int k =i+1; k < n; k++){
                S[k] = '0';
            }
        }
    }
    cout<<S<<endl;
    return 0;
}