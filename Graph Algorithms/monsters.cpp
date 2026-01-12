#include<bits/stdc++.h>
using namespace std;
using pr = pair<int,int>;

vector<char> dir = {'U' , 'D' , 'L' , 'R'};
vector<int> dx = {-1 , 1 , 0 , 0};
vector<int> dy = {0 , 0 , -1 , 1};

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<char>> grids(n , vector<char>(m));
    pr start = {-1 , -1} , finish = {-1 , -1};

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grids[i][j];
            if(grids[i][j] == 'A') start = {i,j};
        }
    }

    vector<vector<int>> monster_time(n , vector<int>(m , INT_MAX));
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    vector<vector<char>> parent(n , vector<char>(m));

    queue<pr> q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grids[i][j] == 'M'){
                q.push({i , j});
                monster_time[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();
        for(int d = 0 ; d < 4 ; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grids[nx][ny] != '#'
            && monster_time[nx][ny] > monster_time[x][y] + 1){
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q.push({nx , ny});
            }
        }
    }
    bool finished = false;
    q.push(start);
    vector<vector<int>> dist(n , vector<int>(m , 0));
    visited[start.first][start.second] = true;
    while(!q.empty() && !finished){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            finish = {x ,y};
            finished = true;
            break;
        }

        for(int d = 0 ; d < 4 ; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
            grids[nx][ny] != '#' && !visited[nx][ny]
            && dist[x][y] + 1 < monster_time[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx , ny});
                parent[nx][ny] = dir[d];
            }
        }

    }

    if(!finished){
        cout << "NO" << endl;
        return 0;
    }

    vector<char> ans;
    pr curr = finish;
    while(curr != start){
        char dirr = parent[curr.first][curr.second];
        ans.push_back(dirr);
        int idx = find(dir.begin() , dir.end() , dirr) - dir.begin();
        curr.first -= dx[idx];
        curr.second -= dy[idx];
    }

    reverse(ans.begin() , ans.end());

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i];
    cout << endl;
    return 0;


}