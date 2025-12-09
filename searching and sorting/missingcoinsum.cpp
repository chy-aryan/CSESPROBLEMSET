#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    sort(coins.begin() , coins.end());
    long long total = 0;
    for(int i  = 0 ; i < coins.size() ; i++){
        if(coins[i] > total + 1){
           break;
        }
        total += coins[i];
    }
    cout << total + 1 << endl;
}