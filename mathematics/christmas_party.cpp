#include<bits/stdc++.h>
#define ll long long
#define mode 1000000007
using namespace std;
int main(){
  ll n;
  cin >> n;
  vector<ll> dp(n+1);
  dp[0] = 1;
  dp[1] = 0;
  for(ll i = 1 ; i <= n ; i++){
    dp[i] = ((i-1)*((dp[i-1] + dp[i-2])%mode))%mode;
  }
  cout << dp[n] << endl;
}