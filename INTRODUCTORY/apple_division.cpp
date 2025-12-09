#include<bits/stdc++.h>
using namespace std;
long long solve(int idx , vector<long long> &weight , long long sum1 , long long sum2 , int n){
    if(idx == n){
        return abs(sum1 - sum2);
    }
    long long choose = solve(idx + 1 , weight , sum1 + weight[idx] , sum2 , n);
    long long notchoose = solve(idx + 1 , weight , sum1 , sum2 + weight[idx] , n);
    return min(choose , notchoose);
}
int main(){
    int n;
    cin >> n;
    vector<long long> weight(n);
    for(int i = 0 ; i < n ; i++){
        cin >> weight[i];
    }
    long long ans = solve(0 , weight , 0 , 0 , n);
    cout << ans << endl;

}