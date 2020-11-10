#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll powmod(ll x, ll y) {
    ll res = 1;
    for (ll i = 0; i < y; i++) {
        res = res * x % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n; cin >> n;
    ll ans = powmod(10, n) - 2 * powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans = (ans + mod) % mod;
    cout << ans;
    
    return 0;
}
