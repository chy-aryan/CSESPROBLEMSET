#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    ll deadline = 0 , finishtime = 0;
    ll currtime = 0;
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
        deadline += arr[i].second;
    }
    sort(arr.begin() , arr.end());
    for(int i = 0 ; i < n ; i++){
        currtime += arr[i].first;
        finishtime += currtime;
    }
    cout << deadline - finishtime << endl;
}