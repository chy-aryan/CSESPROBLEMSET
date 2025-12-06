#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    for(long long i = 1 ; i <= n ; i++){
    long long total = ((i*i)*(i*i -1))/2;
    long long attack = 4*(i-1)*(i-2); 
    long long ans = total - attack;
    cout << ans << endl;
    }
    return 0;
}
/* Here it will attack when there will be 2*3 or 3*2 block , in each block it will have two
    ways to attack , thus we will find the total number of 2*3 or 3*2 block in n*n board qand then multiply by 2 and add them*/