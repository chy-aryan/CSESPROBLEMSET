#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> solve(int n , int from , int help , int to){
   if(n==1){
    return {{from,to}};
   }
   vector<pair<int,int>> moveone = solve(n-1 , from , to , help);
   moveone.push_back({from,to});
   vector<pair<int,int>> movetwo = solve(n-1 , help , from , to);
   for(int i = 0 ; i < movetwo.size() ; i++){
    moveone.push_back(movetwo[i]);
   }
   return moveone;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans = solve(n , 1 , 2 , 3);
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}