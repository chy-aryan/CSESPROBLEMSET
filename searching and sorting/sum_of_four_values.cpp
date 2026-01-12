#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    unordered_map<int ,  vector<pair<int,int>>> mp;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            int sum = arr[i] + arr[j];
            mp[sum].push_back({i,j});
        }
    }
    bool check = false;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        int ele1 = it->first;
        const auto& pairs1 = it->second;
        int rem = x - ele1;
        if(mp.find(rem) != mp.end()){
            const auto& pairs2 = mp[rem];
            for(auto pair1 : pairs1){
                for(auto pair2 : pairs2){
                    if(pair1.first != pair2.first && pair1.first != pair2.second && pair1.second != pair2.first && pair1.second
                    != pair2.second){
                        cout << pair1.first + 1 << " " << pair1.second + 1 << " " << pair2.first + 1 << " " << pair2.second + 1 << endl;
                        check = true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
        }

    }
    if(!check) cout << "IMPOSSIBLE" << endl;
}