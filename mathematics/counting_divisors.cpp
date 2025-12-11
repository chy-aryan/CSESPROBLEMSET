#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int cnt = 0;
        for(int i = 1 ; i <= sqrt(x) ; i++){
            if(x % i == 0){
                if(i == sqrt(x)) cnt++;
                else cnt += 2;
            }
        }
        cout << cnt << endl;
    }
}