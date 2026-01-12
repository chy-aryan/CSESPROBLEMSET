#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> customers(n , vector<int>(3));
    for(int i = 0 ; i < n ; i++){
        cin >> customers[i][0];
        cin >> customers[i][1];
        customers[i][2] = i;
    } 
    sort(customers.begin() , customers.end());
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> occupied;
    int roomcnt = 0;
    vector<int> ans(n);
    for(int i = 0 ; i < n ; i++){
        if(occupied.empty() || occupied.top().first >= customers[i][0]){
            roomcnt++;
            ans[customers[i][2]] = roomcnt;
            occupied.push({customers[i][1] , roomcnt});
        }
        else {
            int roomno = occupied.top().second;
            ans[customers[i][2]] = roomno;
            occupied.pop();
            occupied.push({customers[i][1] , roomno});
        }
    }
    cout << roomcnt << endl;
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}