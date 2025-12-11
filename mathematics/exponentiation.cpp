#include<bits/stdc++.h>
#define ll long long
# define mode 1000000007ll
using namespace std;
ll solve(ll a , ll b){
    if(b == 0) return 1;
    else {
       ll  half= solve(a , b/2);
       ll res = (half*half)%mode;
       if(b % 2 != 0) return (res*a) % mode;
       else return res;

    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
      ll a , b;
      cin >> a >> b;
      ll ans = solve(a , b);
      cout << ans << endl;
    }
}