#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> duration(n);
    for(int i = 0 ; i < n ; i++){
        cin >> duration[i].first >> duration[i].second;
    }
    sort(duration.begin() , duration.end() , [](auto &a , auto &b){
        return a.second < b.second;
    });
    int cnt = 0;
    int endtime = -1;
    for(int i = 0 ; i < n ; i++){
        if(duration[i].first >= endtime){
            cnt++;
            endtime = duration[i].second;
        }
    }
    cout << cnt << endl;

}