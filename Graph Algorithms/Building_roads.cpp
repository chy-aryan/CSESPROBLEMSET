#include<bits/stdc++.h>
using namespace std;

void dfs(int n , vector<bool>& visited , vector<vector<int>>& graph){
    visited[n] = true;
    for(int i : graph[n]){
      if(!visited[i]) dfs(i , visited , graph);
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1 , false);
    for(int i = 0 ; i < m ; i++){
        int u ,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> represent;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
           represent.push_back(i);
           dfs(i , visited , graph);
        }
    }

    int p = represent.size() - 1;
    cout << p << endl;
    for(int i = 1 ; i < p+1 ; i++){
        cout << represent[0] << " " << represent[i] << endl;
    }
}