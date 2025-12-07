#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ele = 5;
    int cnt = 0;
    while(1){
      int num = n/ele;
      if(num == 0) break;
      cnt += num;
      ele *= 5;
    }
    cout << cnt << endl;
}
/*We are counting the number of times 5 appears*/