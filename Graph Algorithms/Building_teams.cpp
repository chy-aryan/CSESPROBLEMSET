#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> assign(n+1 , -1);
    vector<vector<int>> graphs(n+1);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++){
        if(assign[i] != -1) continue;

        queue<int> q;
    q.push(i);
    assign[i] = 1;
    while(!q.empty()){
        int temp = q.front();
        int grp = assign[temp];
        q.pop();
        for(auto it : graphs[temp]){
            if(assign[it] == grp) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if(assign[it] != -1) continue;
            assign[it] = grp == 1 ? 2 : 1;
            q.push(it);
        }
    }

    }
    for(int i = 1 ; i <= n ; i++){
        cout << assign[i] << " ";
    }
    cout << endl;
}