#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    long long maxsum = INT_MIN;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(sum < 0) sum = 0;
        sum += arr[i];
        maxsum = max(maxsum , sum);
    }
    cout << maxsum << endl;
}