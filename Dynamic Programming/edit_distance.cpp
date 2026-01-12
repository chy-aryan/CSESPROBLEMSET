#include<bits/stdc++.h>
using namespace std;
int main(){
    string a , b;
    cin >> a ;
    cin >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1 , vector<int>(m+1));
    for(int i = 0 ; i <= m ; i++) dp[0][i] = i;
    for(int i = 0 ; i <= n ; i++) dp[i][0] = i;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                int opt1 = dp[i-1][j-1] + 1;
                int opt2 = dp[i-1][j] + 1;
                int opt3 = dp[i][j-1] + 1;
                int mini = min(opt1 , opt2);
                dp[i][j] = min(mini , opt3);
            }
        }
    }
    cout << dp[n][m] << endl;
}