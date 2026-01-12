#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& arr , ll cur , ll req){
    ll num = 0;
    ll sum = 0;
    for(int i = 0 ; i < arr.size() ; i++){
       sum += arr[i];
       if(sum > cur){
          num++;
          sum = arr[i];
       }
    }
    if(num + 1 <= req) return true;
    else return false;
}

int main(){
   ll n , k;
   cin >> n >> k;
   vector<ll> arr(n);
   ll maxi = LLONG_MIN , total = 0;
   for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
    total += arr[i];
    maxi = max(maxi , arr[i]);
   }
   ll ans = total;
   ll low = maxi , high = total;
   while(low < high){
    ll mid = low + (high-low)/2;
    bool find = check(arr , mid , k);
    if(find) {
        ans = mid;
        high =  mid;
    }
    else low = mid+1;
   }
   cout << ans << endl;
}