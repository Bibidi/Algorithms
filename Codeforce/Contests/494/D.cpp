#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> cnt(31);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[__builtin_ctz(t)]++;
    }
    
    while (q--) {
        int x; cin >> x;
        
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int t = min(x >> i, cnt[i]);
            x -= (1 << i) * t;
            ans += t;
        }
        
        if (x > 0)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
