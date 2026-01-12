#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   ll n , m;
   cin >> n >> m;
   vector<vector<pair<ll,ll>>> graph(n+1);
   for(int i = 0 ; i < m ; i++){
       ll u , v , l;
       cin >> u >> v >> l;
       graph[u].push_back({v,l});
   }

   vector<ll> dist(n+1 , LLONG_MAX);
   dist[1] = 0;

   priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<>> pq;
   pq.push({0,1});

   while(!pq.empty()){
    auto it = pq.top();
    auto curr = it.first;
    auto node = it.second;
    pq.pop();
    if(dist[node] < curr) continue;

    for(auto it : graph[node]){
        auto adj = it.first;
        auto len = it.second;
        if(dist[node] + len < dist[adj]) {
            dist[adj] = dist[node] + len;
            pq.push({dist[adj] , adj});
        }
    }
   }

   for(int i = 1 ; i <= n ; i++){
    cout << dist[i] << " ";
   }
   cout << endl;
}