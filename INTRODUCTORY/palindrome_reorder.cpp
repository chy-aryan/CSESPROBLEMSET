#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int> mp;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        mp[s[i]]++;
    }
    char odd = '@';
    bool check = false;
    for(auto &it : mp){
        if(it.second % 2 != 0 ) {
            if(odd != '@') {
                check = true;
                break;
            }
            else {
                odd = it.first;
            }
        }
    }
    string left = "";
    string mid;
    if(odd != '@') mid = odd;
    if(check){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for(auto &it : mp){
        left.append(it.second / 2 , it.first);
    }
    string right = left;
    
    reverse(right.begin() , right.end());
    cout << left + mid + right << endl;

    
}