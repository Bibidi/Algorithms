#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    set<int, greater<int>> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int m; cin >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (s.lower_bound(t) != s.end()) {
            s.erase(s.lower_bound(t));
            ans++;
        }
        else break;
    }
    cout << ans;
    return 0;
}
