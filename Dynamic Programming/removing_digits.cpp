#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n + 1 , 100000000);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        int temp = i;
        while(temp != 0){
            int x = temp % 10;
            if(x != 0) dp[i] = min(dp[i] , dp[i-x] + 1);
            temp /= 10;
        }
    }
    cout << dp[n] << endl;
}