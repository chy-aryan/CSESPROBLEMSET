#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , q;
    cin >> n >> q;
    vector<vector<int>> arr(n+1 , vector<int>(n+1));
    for(int i = 0 ; i <= n ; i++) arr[i][0] = 0;
    for(int i = 0 ; i <= n ; i++) arr[0][i] = 0;
    char ch;
    int prev;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> ch;
            prev = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if(ch == '*') arr[i][j] = prev + 1;
            else arr[i][j] = prev;
        }
    }
    int y1 , x1 , y2 , x2;
    while(q--){
    cin >> y1 >> x1 >> y2 >> x2;
    cout << arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1];
    cout << endl;
    }

}