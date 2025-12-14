#include<bits/stdc++.h>
using namespace std;


int rmqans(vector<int>& st , int ss , int se , int qs , int qe , int idx){
   if(ss >= qs && se <= qe) return st[idx];

   if(se < qs || ss > qe) return INT_MAX;

   int mid = ss + (se-ss)/2;

   return min(rmqans(st , ss , mid , qs , qe , 2*idx + 1) , rmqans(st , mid + 1 , se , qs , qe , 2*idx + 2));

}

int rmq(vector<int>& st , int qs , int qe , int n){
    if(qs < 0 || qe > n-1 || qs > qe) return -1;
    return rmqans(st , 0 , n-1 , qs , qe , 0);
}

int fillst(vector<int>& arr , vector<int>& st , int ss , int se , int idx){
    if(ss == se){
        st[idx] = arr[ss];
        return st[idx];
    }

    int mid = ss + (se-ss)/2;

    st[idx] = min(fillst(arr , st , ss , mid , 2*idx + 1) , fillst(arr , st , mid + 1 , se , 2*idx + 2));
    return st[idx];
}

vector<int> constructst(vector<int>& arr , int n){
    int x = (int)(ceil(log2(n)));
    int maxsize = 2*pow(2 , x) - 1;
    vector<int> st(maxsize);
    fillst(arr , st , 0 , n-1 , 0);
    return st;
}

int main(){
    int n , q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    vector<int> st = constructst(arr , n);
    while(q--){
        int a , b;
        cin >> a >> b;
        cout << rmq(st , a-1 , b-1 , n) << endl;
    }
}