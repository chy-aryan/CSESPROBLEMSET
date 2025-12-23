#include<bits/stdc++.h>
#define ll long long
#define mode 1000000007
using namespace std;
int main(){
    ll n;
    cin >> n;
    vector<vector<char>> grid(n , vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++) cin >> grid[i][j];
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << "0" <<endl;
        return 0;
    }
    vector<vector<ll>> dp(n+1 , vector<ll>(n+1));
    for(int i = 0 ; i <= n ; i++){
        dp[n][i] = 0;
        dp[i][n] = 0;
    }
    dp[n-1][n-1] = 1;
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i == n-1 && j == n-1) continue;
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%mode;
        }
    }
    cout << dp[0][0] << endl;
}
    
    