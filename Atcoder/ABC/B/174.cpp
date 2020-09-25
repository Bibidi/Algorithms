#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    long d; cin >> d;
    d = d * d;
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        long x, y; cin >> x >> y;
        if (x * x + y * y <= d)
            cnt++;
    }
    cout << cnt;
    
    return 0;
}
