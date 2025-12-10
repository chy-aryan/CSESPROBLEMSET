#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin() , s.end());
    set<string> str;
    do{
        str.insert(s);
    }while(next_permutation(s.begin() , s.end()));
    cout << str.size() << endl;
    for(auto it : str){
        cout << it << endl;
    }
}