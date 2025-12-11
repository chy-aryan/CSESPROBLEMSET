#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1 ; i <= n ; i++) q.push(i);
    bool flag = false;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        if(flag) cout << ele << " ";
        else q.push(ele);
        flag = !flag;
    }

}
/*We have used queue to track which elements to remove*/