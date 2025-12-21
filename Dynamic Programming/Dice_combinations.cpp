#include<bits/stdc++.h>
#define mode 1000000007
#define ll long long
using namespace std;

int main(){
   int n;
   cin >> n;
   vector<int> dp(n+1);
   dp[0] = 1 , dp[1] = 1;
   for(int i = 2 ; i <= n ; i++){
    int j = 1;
    while( j <= 6 && i - j >= 0){
        dp[i] = (dp[i]%mode + dp[i-j]%mode)%mode;
        j++;
    }
   }
   cout << dp[n] << endl;
}