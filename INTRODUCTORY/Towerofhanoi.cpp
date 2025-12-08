#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> solve(int n , int i , int j){
   if(n==1){
    return {{i,j}};
   }
   vector<pair<int,int>> moveone = solve(n-1 , i , j-1);
   moveone.push_back({i,j});
   vector<pair<int,int>> movetwo = solve(n-1 , j-1 , j);
   for(int i = 0 ; i < movetwo.size() ; i++){
    moveone.push_back(movetwo[i]);
   }
   return moveone;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans = solve(n , 1 , 3);
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}