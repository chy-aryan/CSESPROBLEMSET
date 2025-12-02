#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int , int> mp;
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin >> ele;
        mp[ele]++;
    }
    int cnt = 0;
    for(auto it : mp){
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}