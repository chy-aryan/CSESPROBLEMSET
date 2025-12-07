#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long a , b;
        cin >> a >> b;
        bool check = false;
        long long sum = a+b;
        long long maxi = max(a , b);
        long long mini = min(a,b);
        if((a+b) % 3 == 0 && maxi <= 2*mini ) check = true;
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}