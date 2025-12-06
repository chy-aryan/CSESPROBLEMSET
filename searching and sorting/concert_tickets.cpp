#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n , m;
    cin >> n >> m;
    vector<long long> ans(m , -1);
    map<int,int> mp;
    for(long long i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(long long i = 0 ; i < m ; i++){
        int x;
        cin >> x;
        auto it = mp.upper_bound(x);
        if(it != mp.begin()){
            it--;
            ans[i] = it->first;
            it->second--;
            if(it -> second == 0) mp.erase(it);
        }
    }
    for(long long i = 0 ; i < m ; i++){
        cout << ans[i] << endl;
    }
}