#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    int cnt = 0;
    vector<int> weight(n);
    for(int i = 0 ; i < n ; i++){
        cin >> weight[i];
    }
    sort(weight.begin() , weight.end());
    int i = 0 , j = n-1;
    while(i <= j){
        if(weight[i] + weight[j] <= x){
            i++;
            j--;
        }
        else {
            j--;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
/*Here we will be pairing one lightest and one heaviest element to get minimum answer ,
if we think to pair adjacent element , then it will be wrong because for heaviest element , we will try to pair two 
closely heaviest element , which may not fit under same gondola and may not give minimum answer*/ 
