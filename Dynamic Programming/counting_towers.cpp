#include<bits/stdc++.h>
#define ll long long
#define mode 1000000007
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<vector<ll>> dp(1000005 , vector<ll>(2));
    while(t--){
        ll n;
        cin >> n;
        dp[n][0] = 1;
        dp[n][1] = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            dp[i][0] = ((2ll *dp[i+1][0])%mode + dp[i+1][1])%mode;
            dp[i][1] = ((4ll *dp[i+1][1])%mode + dp[i+1][0])%mode;
        }
        cout << (dp[1][0] + dp[1][1])%mode << endl;
    }
}