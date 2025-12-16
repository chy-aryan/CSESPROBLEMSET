#include<bits/stdc++.h>
#define ll long long
using namespace std;

void updateval(vector<ll>& st , int idx , int ss , int se , int qs , int qe , ll val){
   if(se < qs || ss > qe) return ;
   if(qs <= ss && qe >= se){
    st[idx] += val;
    return;
   }
   int mid = ss + (se-ss)/2;
   updateval(st , 2*idx + 1 , ss , mid , qs , qe , val);
   updateval(st , 2*idx + 2 , mid + 1 , se , qs , qe , val);
   return;
}

ll getans(vector<ll>& st , int stidx , vector<ll>& arr , int ss , int se , int idx , ll ans){
   if(se < idx  || ss > idx) return 0;
   if(ss == se){
    return ans + arr[ss];
   }
   int mid = ss + (se - ss)/2;
   if(idx <= mid) return getans(st , 2*stidx + 1 ,  arr , ss , mid , idx , st[stidx] + ans);
   else return getans(st , 2*stidx + 2 ,  arr , mid + 1 , se , idx , st[stidx] + ans);

}

ll ans(vector<ll>& st , vector<ll>& arr , int idx, int n){
    if(idx < 0 || idx > n-1) return -1;
    return getans(st , 0 , arr , 0 , n-1 , idx , 0);
}

vector<ll> constructst(vector<ll>& arr , int n){
    int maxsize = 4*n;
    vector<ll> st(maxsize , 0);
    return st;
}

int main(){
    int n , q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    vector<ll> st = constructst(arr , n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll a , b , u;
            cin >> a >> b >> u;
            updateval(st , 0 , 0 , n-1 , a-1 , b-1 , u);
        }
        else {
            int k;
            cin >> k;
            cout << ans(st , arr , k-1 , n) << endl;
        }
    }
}