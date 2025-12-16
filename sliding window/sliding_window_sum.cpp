#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
 ll n , k;
 cin >> n >> k;
 ll x , a , b , c;
 cin >> x >> a >> b >> c;
 ll xore = 0 , sum = x;
 ll left = 0 , right = 0;
 vector<ll> arr;
 arr.push_back(x);
 while(right <= n-1){
    if(right - left + 1 == k) {
        xore ^= sum;
        sum -= arr[left];
        left++;
    }

    ll next = ((a%c * arr.back())%c + b%c + c)%c;
    sum += next;
    arr.push_back(next);
    right++;
 }
 cout << xore << endl;
}