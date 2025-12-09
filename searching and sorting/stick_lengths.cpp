#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> sticks(n);
    for(int i = 0 ; i < n ; i++){
        cin >> sticks[i];
    }
    sort(sticks.begin() , sticks.end());
    int med = sticks[n/2];
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += abs(sticks[i] - med);
    }
    cout << ans << endl;
}