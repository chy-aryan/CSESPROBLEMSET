#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,  
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

int main(){
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    ordered_multiset ms;

    for(int i = 0 ; i < n ; i++){
        ms.insert(arr[i]);
        if(i >= k){
            auto it = ms.find_by_order(ms.order_of_key(arr[i-k]));
            ms.erase(it);
        }
        if(i >= k-1){
            int idx = (k-1)/2;
            cout << *ms.find_by_order(idx) << " ";
        }
    }
    cout << endl;

}