#include<bits/stdc++.h>
#define ll long long
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
    string s;
    cin >> s;
    ll n = s.size();
    map<char , int> mp;
    for(ll i = 0 ; i < s.size() ; i++) mp[s[i]]++;
    ll fact[s.size() + 1] , invfact[s.size() + 1];
    fact[0] = 1;
    for(ll i = 1 ; i <= s.size() ; i++) fact[i] = (fact[i-1]*i)%mode;
    invfact[s.size()] = power(fact[s.size()] , mode - 2);
    for(int i = s.size() - 1 ; i >= 0 ; i--) invfact[i] = (invfact[i+1]*(i+1))%mode;

    ll ans = fact[s.size()];
    for(auto it : mp){
        ans = (ans*invfact[it.second])%mode;
    }
    ans %= mode;
    ans = (ans + mode)%mode;
    cout << ans << endl;
}