#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll maxi = INT_MIN , sum = 0;
    ll ele;
    for(int i = 0 ; i < n ; i++){
        cin >> ele;
        maxi = max(maxi , ele);
        sum += ele;
    }
    cout << max(sum , 2*maxi) << endl;
}
/*Refer Gfg tutorial if confusing*/