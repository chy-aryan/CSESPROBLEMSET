#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mode;
        a = a * a % mode;
        b >>= 1;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long total = modpow(2, n * n);
    
    long long rot180;
    if (n % 2 == 0){
        rot180 = modpow(2, n * n / 2);
    }
    else {
        rot180 = modpow(2, (n * n + 1) / 2);
    }

    long long rot90;
    if (n % 2 == 0){
        rot90 = modpow(2, n * n / 4);
    }
    else{
        rot90 = modpow(2, (n * n + 3) / 4);
    }

    long long ans = (total + rot180 + 2 * rot90) % mode;
    ans = ans * modpow(4, mode - 2) % mode;
    cout << ans << "\n";
}
