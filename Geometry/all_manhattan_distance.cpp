#include<bits/stdc++.h>
#define ll long long
using namespace std;

void print(__int128 n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    string s = "";
    while (n > 0) {
        s += (char)((n % 10) + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> hori(n);
    vector<ll> vert(n);
    for(int i = 0 ; i < n ; i++){
        cin >> hori[i];
        cin >> vert[i];
    }
    sort(hori.begin() , hori.end());
    sort(vert.begin() , vert.end());
    __int128 xans = 0 , yans = 0 , prefix = 0;
    for(int i = 0 ; i < n ; i++){
        xans += (__int128)(i)*hori[i] - prefix;
        prefix += hori[i];
    }
    prefix = 0;
    for(int i = 0 ; i < n ; i++){
        yans += (__int128)i*vert[i] - prefix;
        prefix += vert[i];
    }
    __int128 totalans = xans + yans;
    print(totalans);
    
}