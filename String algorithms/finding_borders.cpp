#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int len = 0;
    vector<int> lps(n , 0);
    int i = 1;
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else if(len == 0){
            lps[i] = 0;
            i++;
        }
        else {
            len = lps[len-1];
        }
    }
    vector<int> borders;
     i = lps[n-1];
    while(i > 0){
        borders.push_back(i);
        i = lps[i-1];
    }
    sort(borders.begin() , borders.end());
   for(auto it : borders){
    cout << it << " ";
   }
   cout << endl;

}