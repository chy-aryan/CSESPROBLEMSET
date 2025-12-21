#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   ll n;
   cin >> n;
   vector<pair<ll,ll>> coordinates(n+1);
   for(int i = 0 ; i < n ; i++){
     cin >> coordinates[i].first >> coordinates[i].second ;
   }
   coordinates[n].first = coordinates[0].first;
   coordinates[n].second = coordinates[0].second;

   ll ans = 0;

   for(int i = 0 ; i < n ; i++){
    ans += (coordinates[i].first*coordinates[i+1].second - coordinates[i].second*coordinates[i+1].first);
   }

   cout << abs(ans) << endl;
}