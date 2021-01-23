#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll cntT[1 << 21], distT[1 << 21];
ll base, n;

void update(ll k) {
    k += base;
    cntT[k]++;
    distT[k] += (k - base);
    for (k /= 2; k > 0; k /= 2) {
        cntT[k] = cntT[2 * k] + cntT[2 * k + 1];
        distT[k] = distT[2 * k] + distT[2 * k + 1];
    }
}

ll dist(ll a, ll b) {
    a += base; b += base;
    ll res = 0;
    while (a <= b) {
        if (a % 2 == 1) res += distT[a++];
        if (b % 2 == 0) res += distT[b--];
        a /= 2; b /= 2;
    }
    return res;
}

ll cnt(ll a, ll b) {
    a += base; b += base;
    ll res = 0;
    while (a <= b) {
        if (a % 2 == 1) res += cntT[a++];
        if (b % 2 == 0) res += cntT[b--];
        a /= 2; b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (base = 1; base < 200001; base *= 2);
    
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        ll cur = (t * cnt(0, t - 1) - dist(0, t - 1)) + (dist(t + 1, 200000) - t * cnt(t + 1, 200000));
        update(t);
        if (i == 0) continue;
        ans = ((ans % MOD) * (cur % MOD)) % MOD;
    }
    cout << ans;
}
