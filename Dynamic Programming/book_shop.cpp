#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0 ; i < n ; i++) cin >> prices[i];
    for(int i = 0 ; i < n ; i++) cin >> pages[i];
    vector<vector<int>> dp(n+1 , vector<int>(x+1));
    for(int i = 0 ; i <= x ; i++) dp[0][i] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= x ; j++){
            int price = prices[i-1];
            int page = pages[i-1];

            int pick = j >= price ? dp[i-1][j - price] + page : 0;
            int notpick = dp[i-1][j];
            dp[i][j] = max(pick , notpick);
        }
    }
    cout << dp[n][x] << endl;
}