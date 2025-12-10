#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
ll n;
cin >> n;
vector<ll> sizes(n);
for(int i = 0 ; i < n ; i++){
    cin >> sizes[i];
}
ll ans = 0;
multiset<ll> top;
for(int i = 0 ; i < n ; i++){
    auto it = top.upper_bound(sizes[i]);
    if(it == top.end()){
        top.insert(sizes[i]);
        ans++;
    }
    else {
        top.erase(it);
        top.insert(sizes[i]);
    }
}
cout << ans << endl;
}
