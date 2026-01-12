#include<bits/stdc++.h>
using namespace std;
 vector<int> xs = {-1 , 0 , 1 , 0};
 vector<int> ys = {0 , 1 , 0 , -1};

void dfs(int x , int y , vector<vector<char>>& grids , vector<vector<bool>>& visited){
    visited[x][y] = true;
    int n = grids.size();
    int m = grids[0].size();
    for(int i = 0 ; i < 4 ; i++){
       int nextx = x + xs[i];
       int nexty = y + ys[i];
       if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && grids[nextx][nexty] == '.' && !visited[nextx][nexty]) dfs(nextx , nexty , grids , visited);
    }
    return;
}

int main(){
   int n , m;
   cin >> n >> m;
   vector<vector<char>> grids(n , vector<char>(m));
   for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        cin >> grids[i][j];
    }
   }
   vector<vector<bool>> visited(n , vector<bool>(m , false));
   int rooms = 0;
   for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        if(grids[i][j] == '.' && !visited[i][j]){
            dfs(i , j , grids , visited);
            rooms++;
        }
    }
   }
   cout << rooms << endl;
   return 0;
}