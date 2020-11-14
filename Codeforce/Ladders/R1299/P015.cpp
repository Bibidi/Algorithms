#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    double res = 0.0;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        res += x;
    }
    
    cout << res / n;
    
    return 0;
}
