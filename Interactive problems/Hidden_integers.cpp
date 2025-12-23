#include<bits/stdc++.h>
using namespace std;
int main(){
    int low = 1 , high = 1000000000;
    while(low < high){
        int mid = low + (high-low)/2;
        cout << "? " << mid << endl;
        cout.flush();
        string ans;
        cin >> ans;
        if(ans == "YES") low = mid + 1;
        else high = mid;
    }
    cout << "! " << low << endl;
}