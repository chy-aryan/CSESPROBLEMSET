#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int maxlen = INT_MIN;
    int prev = 0;
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
       if(mp.find(arr[i]) != mp.end()){
        prev = max(prev , mp[arr[i]] + 1);
       }
       maxlen = max(maxlen , i - prev + 1);
       mp[arr[i]] = i;
    }
    if(maxlen == INT_MIN) cout << n << endl;
    else cout << maxlen << endl;
}