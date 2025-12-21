#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n , k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];\
    map<ll , ll > mp;
    ll ans = 0;
    int i = 0 , j = 0;
    while(i <= j && j < n){
       mp[arr[j]]++;
        while(mp.size() > k){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        
       }
       if(mp.size() <= k) ans += j - i + 1;
       j++;
    }
    cout << ans << endl;
}