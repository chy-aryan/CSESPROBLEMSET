#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int prev = 0;
    unordered_map<int , int> mp;
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(mp.find(arr[i]) != mp.end()){
            prev = max(mp[arr[i]] + 1 , prev);
        }
        ans += i-prev+1;
        mp[arr[i]] = i;
    }
    cout << ans << endl;
}