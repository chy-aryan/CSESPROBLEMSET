#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
    ll n , q;
    cin >> n >> q;
    vector<ll> prefix(n+1 , 0);
    ll ele;
    for(int i = 1 ; i <= n ; i++){
        cin >> ele;
        prefix[i] = ele + prefix[i-1];
    }
    int a , b;
    while(q--){
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << endl;
    }
}