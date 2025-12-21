#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    map<int , int> mp;
    int left = 0 , right = 0;
    while(right < n){
        mp[arr[right]]++;

        if(right - left + 1 < k){
            right++;
            continue;
        }

        else {
            cout << mp.size() << " ";
            mp[arr[left]]--;
            if(mp[arr[left]] == 0) mp.erase(arr[left]);
            left++;
            right++;
        }
    }
}