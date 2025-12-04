#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dep(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] >> dep[i];
    }
    sort(arr.begin() , arr.end());
    sort(dep.begin() , dep.end());
    int i = 0 , j = 0;
    int cnt = 0 , maxcnt = 0;
    while(i < n && j < n){
       if(arr[i] < dep[j]){
        cnt++;
        maxcnt = max(cnt , maxcnt);
        i++;
       }
       else{
        cnt--;
        maxcnt = max(cnt , maxcnt);
        j++;
       }
    }
    cout << maxcnt << endl;
    return 0;
}
/*Here we will be sorting the intervals by their arrival and departure time , and we will track both the arrays using pointers 
whenever the arrival time is less than the current departure time , it means one more customer arrives before any customer departs
so we will increase the count and move the arrival pointer next so that there may be scope of more customers arriving till this time 
if arrival time is greater or equal , it means when a new person arrives then this depart pointer will have passed means one person will
be departed till this time , so we will decrease the count and move the depart pointer to next */