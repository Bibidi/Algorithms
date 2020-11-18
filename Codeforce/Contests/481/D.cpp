#include <bits/stdc++.h>
using namespace std;

const int inf = 1000 * 1000;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    
    int ans = inf;
    for (int d0 = -1; d0 <= 1; d0++) {
        for (int d1 = -1; d1 <= 1; d1++) {
            bool ok = true;
            int cnt = abs(d0) + abs(d1);
            int b0 = a[0] + d0;
            int dist = (a[1] + d1) - b0;
            
            for (int i = 2; i < n; i++) {
                int cur = b0 + i * dist;
                int diff = abs(cur - a[i]);
                if (diff > 1) {
                    ok = false;
                    break;
                }
                else if (diff == 1) cnt++;
            }
            
            if (ok) ans = min(ans, cnt);
        }
    }
    if (ans != inf)
        cout << ans;
    else
        cout << -1;
    return 0;
}
