#include<bits/stdc++.h>
#define ll long long
using namespace std;

void updateval(vector<ll>& st , int idx , int ss , int se , int k , int val){
    if(ss == se){
        st[idx] = val;
        return ;
    }
    int mid = ss + (se - ss)/2;

    if(k > mid){
         updateval(st , 2*idx + 2 ,  mid + 1 , se , k , val);
    }
    else  updateval(st , 2*idx + 1 , ss  , mid , k , val);
    st[idx] = st[2*idx +1] + st[2*idx + 2];
    return;
}

ll sumans(vector<ll>& st , int ss , int se , int qs , int qe , int idx){
   if(ss >= qs && se <= qe) return st[idx];

   if(se < qs || ss > qe) return 0;

   int mid = ss + (se-ss)/2;

   return (sumans(st , ss , mid , qs , qe , 2*idx + 1) + sumans(st , mid + 1 , se , qs , qe , 2*idx + 2));

}

ll sum(vector<ll>& st , int qs , int qe , int n){
    if(qs < 0 || qe > n-1 || qs > qe) return -1;
    return sumans(st , 0 , n-1 , qs , qe , 0);
}

ll fillst(vector<ll>& arr , vector<ll>& st , int ss , int se , int idx){
    if(ss == se){
        st[idx] = arr[ss];
        return st[idx];
    }

    int mid = ss + (se-ss)/2;

    st[idx] = (fillst(arr , st , ss , mid , 2*idx + 1) + fillst(arr , st , mid + 1 , se , 2*idx + 2));
    return st[idx];
}

vector<ll> constructst(vector<ll>& arr , int n){
    int maxsize = 4*n;
    vector<ll> st(maxsize);
    fillst(arr , st , 0 , n-1 , 0);
    return st;
}

int main(){
    ll n , q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    vector<ll> st = constructst(arr , n);
    while(q--){
        int a , b , c;
        cin >> a >> b >> c;
        if(a == 1){
            updateval(st , 0 , 0 , n-1 , b-1 , c);
        }
        else cout << sum(st , b-1 , c-1 , n) << endl;
    }
}