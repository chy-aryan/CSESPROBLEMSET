#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
 ll n , k;
 cin >> n >> k;
 ll x , a , b , c;
 cin >> x >> a >> b >> c;
 ll xore = 0;
 vector<ll> arr(n);
 for(int i = 0 ; i < n ; i++){
    if(i == 0) arr[i] = x;
    else {
        arr[i] = ((a*arr[i-1])%c + b%c)%c;
    }
 }
 deque<pair<ll , ll >> dq;
 int i = 0;
 for(int j = 0 ; j < n ; j++){
    while(!dq.empty() && dq.back().first >= arr[j]) dq.pop_back();
    dq.push_back({arr[j] , j});

    if(j - i + 1 < k){
        continue;
    }
    else {
        xore ^= dq.front().first;
        if(dq.front().second == i) dq.pop_front();
        i++;
    }
 }
 cout << xore << endl;

}