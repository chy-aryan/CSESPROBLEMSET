#include<bits/stdc++.h>
using namespace std;
int main(){
    int a , b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1 , vector<int>(b+1 , INT_MAX));

    for(int i = 0 ; i <= a ; i++){
        for(int j = 0 ; j <= b ; j++){
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int m = 1 ; m < i ; m++){
               dp[i][j] = min(dp[i][j] ,dp[i-m][j] + dp[m][j] + 1);
            }
             for(int m = 1 ; m < j ; m++){
               dp[i][j] = min(dp[i][j] ,dp[i][j-m] + dp[i][m] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
}