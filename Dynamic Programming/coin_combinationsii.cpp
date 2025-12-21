#include<bits/stdc++.h>
#define mode 1000000007
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++) cin >> coins[i];
    vector<vector<int>> dp(n+1 , vector<int>(x+1));
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
    for(int i = 1 ; i <= x ; i++) dp[n][i] = 0;

    for(int i = n - 1 ; i >= 0 ; i--){
        for(int sum = 0 ; sum <= x ; sum++){
          int pick = 0;
          if(coins[i] <= sum) pick = dp[i][sum - coins[i]];
          int skip = dp[i+1][sum];
          dp[i][sum] = (pick + skip)%mode;
        }
    }
    cout << dp[0][x] << endl;
}