#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        ll count = 9;
        ll digits = 1;
        ll start = 1;
        while(k > digits*count){
            k -= digits*count;
            digits++;
            count *= 10;
            start *= 10;
        }
        ll num = start + (k-1)/digits;
        ll idx = (k-1)%digits;
        cout << to_string(num)[idx] << endl;
    }

}