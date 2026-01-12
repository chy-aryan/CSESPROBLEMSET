#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<char>> grid(n , vector<char>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }
    pii start , end;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 'A') start = {i , j};
            else if(grid[i][j] == 'B') end = {i , j};
        }
    }
    vector<vector<int>> visited(n , vector<int>(m , 0));
    vector<vector<char>> prevdir(n , vector<char>(m));
    vector<char> directions = {'U' , 'L' , 'R' , 'D'};
    vector<int> xdir = {-1 , 0 , 0 , 1};
    vector<int> ydir = {0 , -1 , 1 , 0};

    queue<pii> q;
    visited[start.first][start.second] = 1;
    q.push(start);

    bool found = false;

    while(!q.empty() && !found){
        auto curr = q.front();
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
           int newrow = curr.first + xdir[d];
           int newcol = curr.second + ydir[d];
           if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol] && grid[newrow][newcol] != '#'){
            visited[newrow][newcol] = 1;
            prevdir[newrow][newcol] = directions[d];
            q.push({newrow , newcol});
            pair<int,int> temp = {newrow , newcol};
            if(temp == end){
                found = true;
                break;
            }
           }
        }
    }
    
    if(!visited[end.first][end.second]){
        cout << "NO" << endl;
        return 0;
    }

    string path;
    pii curr = end;
    while(curr != start){
        char dirr = prevdir[curr.first][curr.second];
        path.push_back(dirr);
        int idx = find(directions.begin() , directions.end() , dirr) - directions.begin();
        curr.first -= xdir[idx];
        curr.second -= ydir[idx];
    }

    reverse(path.begin() , path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;

}