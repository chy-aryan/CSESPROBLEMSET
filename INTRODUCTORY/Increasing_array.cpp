#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int prev , next;
   long long move = 0;
   cin >> prev;
   for(int i = 1 ; i < n ; i++){
     cin >> next;
     if(next < prev) move += prev - next;
     else prev = next;
   } 
   cout << move << endl;
   return 0;
}