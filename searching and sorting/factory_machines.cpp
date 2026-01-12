#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool find(ll val , vector<ll>& arr , ll req){
    ll cnt = 0;
    for(auto it : arr){
       cnt += val/it;
    }
    if(cnt >= req) return true;
    else return false;
}

int main(){
    ll n , t;
    cin >> n >> t;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    ll low = 1 , high = *min_element(arr.begin() , arr.end())*t;
    ll ans = high;
    while(low <= high){
        ll mid = low + (high - low)/2;
        bool check = find(mid , arr , t);
        if(check){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << endl;
}