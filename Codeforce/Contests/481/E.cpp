#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, w;
    cin >> n >> w;
    
    int lo = 0, up = 0, cur = 0;
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cur += t;
        lo = min(lo, cur);
        up = max(up, cur);
    }
    
    if (up > w) {
        cout << 0;
        return 0;
    }
    
    lo = -lo;
    up = w - up;
    
    if (lo <= up)
        cout << up - lo + 1;
    else
        cout << 0;
    return 0;
}
