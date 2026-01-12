#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin() , arr.end());
    bool check = false;
    int idx1 = -1 , idx2 = -1 , idx3 = -1;
    for(int i = 0 ; i < n-2 ; i++){
        int ptr1 = i + 1 , ptr2 = n-1;
        while(ptr1 < ptr2){
            int sum = arr[ptr1].first + arr[ptr2].first;
            if(sum == x - arr[i].first){
                check = true;
                break;
            }
            if(sum < x - arr[i].first) ptr1++;
            else ptr2--;
        }
        if(check){
            idx1 = arr[i].second+1;
            idx2 = arr[ptr1].second+1;
            idx3 = arr[ptr2].second+1;
            break;
        }
    }
    if(check){
        cout << idx1 << " " << idx2 << " " << idx3 << " " << endl;
    }
    else cout << "IMPOSSIBLE" << endl;

}