#include<bits/stdc++.h>
using namespace std;
vector<string> graycode(int n){
    if(n == 1) return {"0" , "1"};
    vector<string> prevcode = graycode(n-1);
    vector<string> revprevcode = graycode(n-1);
    reverse(revprevcode.begin() , revprevcode.end());
    vector<string> ans;
    for(int i = 0 ; i < prevcode.size() ; i++){
        ans.push_back("0" + prevcode[i]);
    }
    for(int i = 0 ; i < revprevcode.size() ; i++){
        ans.push_back("1" + revprevcode[i]);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << endl;
    }
}