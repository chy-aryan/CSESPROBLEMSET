#include<bits/stdc++.h>
#define ll long long
#define Max 2000005
#define mode 1000000007
using namespace std;
ll fact[Max + 1] , invfact[Max + 1];

ll power(ll a , ll b){
  ll res = 1;
  while(b){
    if(b & 1) res = (res*a)%mode;
    a = (a*a)%mode;
    b >>= 1;
  }
  return res;
}
int main(){
  ll n , m;
  cin >> n >> m;
  fact[0] = 1;
  for(ll i = 1 ; i <= Max ; i++) fact[i] = (fact[i-1]*i)%mode;
  invfact[Max] = power(fact[Max] , mode - 2);
  for(ll i = Max -1 ; i >= 0 ; i--) invfact[i] = (invfact[i+1]*(i+1))%mode;
  ll ans = fact[n+m-1];
  ans = ans*invfact[n-1]%mode;
  ans = ans*invfact[m]%mode;
  ans = (ans%mode + mode)%mode;
  cout << ans << endl;
  return 0;
}