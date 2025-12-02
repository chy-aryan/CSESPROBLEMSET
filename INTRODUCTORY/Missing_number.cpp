#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long sum = n*(n+1);
    sum /= 2;
    long long inputsum = 0;
    int ele;
    for(int i = 0 ; i < n -1 ; i++){
        cin >> ele;
        inputsum += ele;
    }
    cout << sum - inputsum << endl;
    return 0;
}