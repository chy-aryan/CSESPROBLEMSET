#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n , k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> prime(k);
    for(int i = 0 ; i < k ; i++) cin >> prime[i];
    for(int i = 1 ; i < (1 << k) ; i++){
        ll num = n;
        int cntset = 0;
        for(int j = 0 ; j < k ; j++){
            if(i & (1<<j)){
                cntset++;
                num /= prime[j];
            }
        }
        if(cntset % 2 != 0) ans += num;
        else ans -= num;
    }
    cout << ans << endl;
}