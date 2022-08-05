#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, K, cnt;
int a[MAX];
void inputData(){
    cnt = 0;
    cin >> n>>K;
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
}
int bs(int first, int last, int key){
    if(first <= last){
        int mid = first + (last-first)/2;
        if(a[mid] == key) return 1+bs(first, mid-1, key)+bs(mid+1, last, key);
        else{
            if(a[mid] > key) return bs(first, mid-1, key);
            else{
                return bs(mid+1, last, key);
            }
        }
    }
    return 0;
}

int main(){
    inputData();
    sort(a, a+n);
    for(int  i=0; i <n-2; i++){
        for(int j = i+1; j <n-1; j++){
            if(K-a[i]-a[j] <= 0){
                continue;
            }
            int k = bs(j+1, n-1, K-a[j]-a[i]);
            cnt+= k;
        }
    }
    cout<<cnt;
    return 0;
}