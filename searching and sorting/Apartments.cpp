#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> desired(n);
    vector<int> size(m);
    for(int i = 0 ; i < n ; i++){
        cin >> desired[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> size[i];
    }
    sort(desired.begin() , desired.end());
    sort(size.begin() , size.end());
    int cnt = 0 , i = 0 , j = 0;
    while(i < n && j < m){
        if(size[j] < desired[i] - k) j++;
        else if(size[j] > desired[i] + k) i++;
        else {
            cnt++;
            i++;
            j++;
        }
    }
    cout << cnt << endl;
    return 0;
}