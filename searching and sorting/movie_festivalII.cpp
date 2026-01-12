#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    vector<pair<int,int>> time(n);
    for(int i = 0 ; i < n ; i++){
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin() , time.end());
    multiset<int> ms;
    int ans = k;
    for(int i = 0 ; i < k ; i++) ms.insert(time[i].second);
    for(int i = k ; i < n ; i++){
        auto mini = ms.begin();
        auto maxi = prev(ms.end());
        if(*mini <= time[i].first){
            ans++;
            ms.erase(mini);
            ms.insert(time[i].second);
        }
        else if(time[i].second < *maxi){
            ms.erase(maxi);
            ms.insert(time[i].second);
        }
    }
    cout << ans << endl;
}