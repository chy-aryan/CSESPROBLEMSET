#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   ll n , x;
   cin >> n >> x;
   vector<int> arr(n);
   for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
   }
   int left = 0 , right = 0;
   ll sum = 0;
   ll cnt = 0;
   while(right < n){
    sum += arr[right];
    while(left <= right && sum > x){
        sum -= arr[left];
        left++;
    }
    if(sum == x) cnt++;
    right++;
   }
   cout << cnt << endl;
}