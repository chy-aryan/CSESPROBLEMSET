#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> cnt(1000001 , 0);
    int ele;
    for(int i = 0 ; i < n ; i++){
         cin >> ele;
         cnt[ele]++;
    }
    int ans;
    for(int i = 1000000 ; i >= 1 ; i--){
        int multiples = 0;
        for(int j = i ; j <= 1000000 ; j += i){
            multiples += cnt[j];
        }
        if(multiples >= 2){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}