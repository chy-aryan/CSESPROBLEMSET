#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> routes(n+1);
    vector<bool> visited(n+1 , false);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        routes[u].push_back(v);
        routes[v].push_back(u);
    }
    vector<int> parent(n+1 , -1);
    bool found = false;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!found && !q.empty()){
        int temp = q.front();
        q.pop();
        for(auto it : routes[temp]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
                parent[it] = temp;
                if(it == n){
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    int curr = n;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin() , path.end());

    cout << path.size() << endl;
    for(int i = 0 ; i < path.size() ; i++){
        cout << path[i] << " ";
    }
    cout << endl;

}