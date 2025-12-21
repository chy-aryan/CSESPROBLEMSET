#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll x1 , y1 , x2 , y2 , x3 , y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll num = y2 - y1;
        ll den = x2 - x1;
        ll lnum = y3 - y1;
        ll lden = x3 - x1;
        ll lmul = lnum*den;
        ll rmul = lden*num;
        ll ans = lmul - rmul;
        if(ans < 0) cout << "RIGHT" << endl;
        else if(ans > 0) cout << "LEFT" << endl;
        else cout << "TOUCH" << endl;
    }
}