#include<bits/stdc++.h>
using namespace std;

bool ask(int i , int j){
     cout << "? " << i << " " << j << endl;
     cout.flush();
     string ans;
     cin >> ans;
     if(ans == "YES") return true;
     return false;
}
int main(){
    int n;
    cin >> n;
    vector<int> idx(n);
    for(int i = 0 ; i < n ; i++){
        idx[i] = i+1;
    }
    stable_sort(idx.begin() , idx.end() , [&](int i , int j){
        return ask(i,j);
    });
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        arr[idx[i]-1] = i+1;
    }
    cout << "! ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout.flush();
    return 0;
}