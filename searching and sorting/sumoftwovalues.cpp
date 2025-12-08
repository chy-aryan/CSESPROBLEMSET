#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin() , arr.end());
    bool check = false;
    int idx1 , idx2;
    int i = 0;
    while(!check && i < n){
        int rem = x-arr[i].first;
        int low = i+1 , high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid].first == rem){
                check = true;
                idx1 = arr[i].second , idx2 = arr[mid].second;
                break;
            }
            else if(arr[mid].first < rem) low = mid + 1;
            else high = mid -1;
        }
        i++;
    }
    if(check){
        cout << idx1 << " " << idx2 << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    
}