#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n , x;
    cin >> n >> x;
   vector<ll> prefix(n+1 , 0);
   map<ll , ll> mp;
   ll ans = 0;
   mp[0] = 1;
   int ele;
   for(int i = 1 ; i <= n ; i++){
    cin >> ele;
    prefix[i] = ele + prefix[i-1];
    ans += mp[prefix[i] - x];
    mp[prefix[i]]++;
   }
   cout << ans << endl;
}