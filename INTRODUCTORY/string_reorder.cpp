#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26 , 0);
    int maxfreq = 0;
    for(int i = 0 ; i < s.size() ; i++){
        cnt[s[i] - 'A']++;
    }
    for(int i = 0 ; i < 26 ; i++) maxfreq = max(maxfreq , cnt[i]);
    if(maxfreq > (n+1)/2){
       cout << "-1" << endl;
       return 0;
    }

    string ans;
    char prev = '*';
    for(int i = 0 ; i < s.size() ; i++){
       for(int j = 0 ; j < 26 ; j++){
        if(cnt[j] == 0) continue;
        if(prev == 'A' + j) continue;
        cnt[j]--;
        maxfreq = *max_element(cnt.begin() , cnt.end());
        int rem = n - i - 1;
        if(maxfreq > (rem + 1)/2) cnt[j]++;
        else {
            ans.push_back('A' + j);
            prev = 'A' + j;
            break;
        }
       }
    }
    cout << ans << endl;
}