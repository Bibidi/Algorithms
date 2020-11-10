#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, T;
    cin >> n >> T;
    
    int t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int ans = T;
    for (int i = 0; i < n-1; i++) {
        ans += min(T, t[i+1] - t[i]);
    }
    cout << ans;
    return 0;
}
