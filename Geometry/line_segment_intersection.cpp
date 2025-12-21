#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll check (ll x1 , ll y1 , ll x2 ,ll y2 ,ll x3 ,ll y3){
        ll num = y2 - y1;
        ll den = x2 - x1;
        ll lnum = y3 - y1;
        ll lden = x3 - x1;
        ll lmul = lnum*den;
        ll rmul = lden*num;
        ll ans = lmul - rmul;
        if(ans < 0) return -1;
        else if(ans > 0) return 1;
        else return 0;
}

bool onsegment(ll x1 , ll y1 , ll x2 ,ll y2 ,ll x3 ,ll y3){
    if(check(x1 , y1 , x2 , y2 , x3 , y3) != 0) return false;
    else {
        if(min(x1 , x2) <= x3 && max(x1 , x2) >= x3 && min(y1 , y2) <= y3 && max(y1 , y2) >= y3) return true;
        else return false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(onsegment(x1 , y1 , x2 , y2 , x3 , y3)) cout << "YES" << endl;
        else if (onsegment(x1 , y1 , x2 , y2 , x4 , y4)) cout << "YES" << endl;
        else if(onsegment(x3 , y3 , x4 , y4 , x1 , y1)) cout << "YES" << endl;
        else if(onsegment(x3 , y3 , x4 , y4 , x2 , y2)) cout << "YES" << endl;

        else if(check(x1 , y1 ,x2 , y2 , x3 , y3)*check(x1 , y1 , x2 , y2 , x4 , y4) < 0 && check(x3 , y3 ,x4 , y4 , x1 , y1)*check(x3 , y3 , x4 , y4 , x2 , y2) < 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}