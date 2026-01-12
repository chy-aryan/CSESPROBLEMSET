#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   ll n;
   cin >> n;
   vector<ll> arr(n);
   for(int i = 0 ; i < n ; i++) cin >> arr[i];
   unordered_map<ll , ll> mp;
   mp[0] = 1;
   ll cnt = 0;
   ll sum = 0;
   for(int i = 0 ; i < n ; i++){
    sum += arr[i];
    ll temp = (sum % n + n ) %n;
    cnt += mp[temp];
    mp[temp]++;
   }
   cout << cnt << endl;
}