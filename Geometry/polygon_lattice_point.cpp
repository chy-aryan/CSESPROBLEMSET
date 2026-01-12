#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    ll area2 = 0;
    for(int i = 0 ; i < n ; i++){
        ll ele = arr[i].first*arr[(i+1)%n].second - arr[(i+1)%n].first*arr[i].second;
        area2 += ele;
    }
    area2 = abs(area2);
    ll boundarypnts = 0;
    for(int i = 0 ; i < n ; i++){
        ll diff1 = abs(arr[i].first - arr[(i+1)%n].first);
        ll diff2 = abs(arr[i].second - arr[(i+1)%n].second);
        boundarypnts += gcd(diff1 , diff2);
    }

    ll rem = (area2 - boundarypnts + 2)/2;
    cout << rem << " " << boundarypnts << endl;
}