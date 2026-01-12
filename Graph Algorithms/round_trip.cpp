#include<bits/stdc++.h>
using namespace std;
int start = -1 , finish = -1;
vector<vector<int>> graphs;
vector<bool> visited;
vector<int> parent;


bool dfs(int node , int par ){
    visited[node] = true;

    for(auto it : graphs[node]){
        if(it == par) continue;
        if(visited[it]){
            start = it;
            finish = node;
            return true;
        }
        parent[it] = node;
        if(dfs(it , node)) return true;
    }
    return false;
}

int main(){
    int n , m;
    cin >> n >> m;
    graphs.resize(n+1);
    visited.assign(n+1 , false);
    parent.assign(n+1 , false);

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i++){
        if(visited[i]) continue;
        if(dfs(i ,-1)) break;
    }

    if(start == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(start);
    int curr = finish;
    while(curr != start){
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(start);
    reverse(cycle.begin() , cycle.end());
    cout << cycle.size() << endl;
    for(int i = 0 ; i < cycle.size() ; i++){
        cout << cycle[i] << " ";
    }
    cout << endl;

}