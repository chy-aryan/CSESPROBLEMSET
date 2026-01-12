#include<bits/stdc++.h>
#define mode 1000000007
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    vector<vector<int>> dp(n+1 , vector<int>(m+1));
    for(int i = 1 ; i <= m ; i++){
        if(arr[0] == 0 || arr[0] == i) dp[1][i] = 1;
        else dp[1][i] = 0;
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(arr[i-1] != 0 && arr[i-1] != j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 0;
            if(j - 1 >= 1 && j - 1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mode;
            if(j  >= 1 && j  <= m) dp[i][j] = (dp[i][j] + dp[i-1][j])%mode;
            if(j + 1 >= 1 && j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mode;
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= m ; i++){
        ans = (ans + dp[n][i])%mode;
    }
    cout << ans << endl;
}