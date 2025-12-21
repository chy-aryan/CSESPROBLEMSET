#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    map<int , int> mp;
    set<int> st;
    for(int i = 0 ; i <= k ; i++){
        st.insert(i);
    }
    for(int i = 0 ; i < n ; i++){
        mp[arr[i]]++;
        if(arr[i] <= k) st.erase(arr[i]);
        if(i >= k){
            mp[arr[i-k]]--;
            if(mp[arr[i-k]] == 0 && arr[i-k] <= k) st.insert(arr[i-k]);
            if(mp[arr[i-k]] == 0) mp.erase(arr[i-k]);
        }
        if(i >= k-1) cout << *st.begin() << " ";
    }
    cout << endl;
}