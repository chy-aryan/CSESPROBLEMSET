#include<bits/stdc++.h>
#define ll long long
#define Max 1000005
#define mode 1000000007
using namespace std;

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
  ll n;
  cin >> n;
  ll fact[Max + 1] , invfact[Max + 1];
  fact[0] = 1;
  for(ll i = 1 ; i <= Max ; i++) fact[i] = (fact[i-1]*i)%mode;
  invfact[Max] = power(fact[Max] , mode - 2);
  for(ll i = Max -1 ; i >= 0 ; i--) invfact[i] = (invfact[i+1]*(i+1))%mode;
  while(n--){
    ll a , b;
    cin >> a >> b;
    ll ans = fact[a];
    ans = (ans*invfact[b])%mode;
    ans = (ans*invfact[a-b])%mode;
    ans = (ans + mode)%mode;
    cout << ans << endl;
  }
  return 0;
}