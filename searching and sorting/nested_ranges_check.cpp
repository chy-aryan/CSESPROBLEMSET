#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    vector<vector<int>> ranges(n , vector<int>(3));
    for(int i = 0 ; i < n ; i++){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
    sort(ranges.begin() , ranges.end() , [](auto& a , auto& b){
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        else {
            return a[1] > b[1];
        }
    });
    vector<int> contains(n , 0);
    vector<int> contained(n , 0);

    int maxend = -1;
    for(int i = 0 ; i < n ; i++){
        if(ranges[i][1] <= maxend) contained[ranges[i][2]] = 1;
        maxend = max(maxend , ranges[i][1]);
    }

    int minend = INT_MAX;
    for(int i = n-1 ; i >= 0 ; i--){
        if(ranges[i][1] >= minend) contains[ranges[i][2]] = 1;
        minend = min(minend , ranges[i][1]);
    }

    for(auto it : contains){
        cout << it << " ";
    }
    cout << endl;
    for(auto it : contained){
        cout << it << " ";
    }
    cout << endl;
}