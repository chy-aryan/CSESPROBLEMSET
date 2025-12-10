#include<bits/stdc++.h>
using namespace std;
int main(){
int x , n;
cin >> x >> n;
vector<int> pos(n);
for(int i = 0 ; i < n ; i++){
    cin >> pos[i];
}
set<pair<int,int>> ranges;
multiset<int> length;
ranges.insert({0,x});
length.insert(x-0);
for(int i = 0 ; i < n ; i++){
    auto it = ranges.upper_bound({pos[i] , 0});
    it--;
    int start = it-> first;
    int end = it-> second;
    ranges.erase(it);
    length.erase(length.find(end-start));
    ranges.insert({start , pos[i]});
    ranges.insert({pos[i] , end});
    length.insert(pos[i] - start);
    length.insert(end - pos[i]);
    cout << *length.rbegin() << " ";
}
}