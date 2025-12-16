#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
 ll n , k;
 cin >> n >> k;
 ll x , a , b , c;
 cin >> x >> a >> b >> c;
 ll xore = 0 , xorr = x;
 ll left = 0 , right = 0;
 vector<ll> arr;
 arr.push_back(x);
 while(right <= n-1){
    if(right - left + 1 == k) {
        xore ^= xorr;
        xorr ^= arr[left];
        left++;
    }

    ll next = ((a%c * arr.back())%c + b%c + c)%c;
    xorr ^= next;
    arr.push_back(next);
    right++;
 }
 cout << xore << endl;
}