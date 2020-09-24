#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, t;
    cin >> n >> x >> t;
    
    int res = (n + x - 1) / x * t;
    cout << res;
    return 0;
}
