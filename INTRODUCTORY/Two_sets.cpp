#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n % 4 != 3 && n % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
        if(n % 4 == 3){
            cout << (n/2) + 1 << endl;
            cout << "1 2 ";
            int i = 4;
            while(i <= n){
                cout << i << " " << i+3 << " ";
                i += 4;
            }
            cout << endl << n/2 << endl << "3 ";
            i = 5;
            while(i+1 <= n){
                cout << i << " " << i+1 << " ";
                i += 4;
            }
            cout << endl;
        }
        else {
            cout << n/2 << endl;
            int i = 1;
            while(i+3 <= n){
                cout << i << " " << i+3 << " ";
                i += 4;
            }
            cout << endl << n/2 << endl;
            i = 2;
            while(i+1 <= n){
                cout << i << " " << i+1 << " ";
                i += 4;
            }
            cout << endl;
        }
    }
    return 0;
}