#include<bits/stdc++.h>
#define ll long long
#define mode 1000000007
using namespace std;
ll expo (ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mode;
        a = (a*a) % mode;
        b >>= 1;
    }
    return res;
}
ll modinverse(ll a){
    return expo(a , mode - 2);
}

ll modsum(ll x){
    return ((x % mode)*((x+1)%mode))%mode * modinverse(2) % mode;
}
int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1 ; i*i <= n ; i++){
        ll x = n/i;
        ll rem = x - i + 1;
        ans = (ans % mode) +  ((i % mode)*(rem % mode))%mode;
        ans  %= mode;
        ll sum = (modsum(x)- modsum(i) + mode)%mode;
        ans = (ans + sum) % mode;
    }
    cout << ans << endl;
}
/* Refer modular arithmatic artcle https://www.geeksforgeeks.org/engineering-mathematics/modular-arithmetic
and for the main concept of Big O (sqrt n) read https://www.geeksforgeeks.org/dsa/sum-divisors-1-n/*/