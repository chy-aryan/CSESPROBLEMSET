#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0 ; i < n ; i++) cin >> arr[i];
  vector<pair<int,int>> v;
  for(int i = 0 ; i < n ; i++){
    if(v.size() == 0) {
        v.push_back({arr[i] , 1});
        continue;
    }
    if(v.back().first == arr[i]) v.back().second++;
    else v.push_back({arr[i] , 1});
    if(v.back().second == 4) v.pop_back();
     }
     int cnt = 0;
     for(int i = 0 ; i < v.size() ; i++){
       cnt += v[i].second;
     }
  cout << cnt << endl;
}