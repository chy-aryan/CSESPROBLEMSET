#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<int , int> mp;
    int ele;
    for(int i = 0 ; i < n ; i++){
        cin >> ele;
        mp[ele] = i;
    }
    int ans = 1;
    for(int i = 1 ; i < n ; i++){
        if(mp[i+1] < mp[i]) ans++;
    }
    cout << ans << endl;
}