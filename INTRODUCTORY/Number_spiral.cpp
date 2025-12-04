#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long y , x;
        cin >> y >> x;
        if(y >= x){
            long long inner = (y-1)*(y-1);
            if(y % 2 != 0){
                cout << inner + x << endl;
            }
            else {
                cout << inner + (2*y -x) << endl;
            }
        }
        else {
            long long inner = (x-1)*(x-1);
            if(x % 2 != 0){
                cout << inner + (2*x - y) << endl;
            }
            else {
                cout << inner + y << endl;
            }
        
        }
    }
    return 0;
}
/* Only observation , whatever is greater will dominate and decide the element that is there at that position , and 
one more thing that is once it is increasing and once it is decreasing*/