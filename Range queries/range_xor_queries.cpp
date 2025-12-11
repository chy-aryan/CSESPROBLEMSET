#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n , q;
    cin >> n >> q;
    vector<ll> xorprefix(n+1 , 0);
    ll ele;
    for(int i = 1 ; i <= n ; i++){
        cin >> ele;
        xorprefix[i] = xorprefix[i-1]^ele;
    }
    int a , b;
    while(q--){
        cin >> a >> b;
        cout << (xorprefix[a-1]^xorprefix[b]) << endl;
    }
}
