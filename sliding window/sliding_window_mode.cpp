#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    map<int , int> freq;
    map<int , set<int>> elelist;
    for(int i = 0 ; i < n ; i++){
        int ele = -1;
        if(freq.find(arr[i]) != freq.end()){
            ele = freq[arr[i]];
        }
        freq[arr[i]]++;
        elelist[freq[arr[i]]].insert(arr[i]);
        if(ele != -1) {
            elelist[ele].erase(arr[i]);
            if(elelist[ele].empty()) elelist.erase(ele);
        }
        if(i >= k){
           int removee =  freq[arr[i-k]];
           freq[arr[i-k]]--;
           if(freq[arr[i-k]] == 0) freq.erase(arr[i-k]);
           elelist[removee].erase(arr[i-k]);
           if(elelist[removee].empty()) elelist.erase(removee);
           if(freq.find(arr[i-k]) != freq.end()){
            elelist[freq[arr[i-k]]].insert(arr[i-k]);
           }
        }
        if(i >= k-1){
            cout << *elelist.rbegin()->second.begin() << " ";
        }
    }
    cout << endl;
}