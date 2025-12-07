#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long mod = 1e9 + 7;
    long long ans = 1;
    for(int i = 0 ; i < n ; i++){
        ans %= mod;
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
}