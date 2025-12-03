#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt = 1 , maxcnt = 1;
    int i = 1;
    while(i < s.size()){
        if(s[i] == s[i-1]) cnt++;
        else cnt = 1;
        maxcnt = max(cnt , maxcnt);
        i++;
    }
    cout << maxcnt << endl;
    return 0;
}