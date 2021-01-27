#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    int dp[c + 1];
    dp[0] = 0;
    for (int i = 1; i <= c; i++) {
        dp[i] = INF;
        for (auto j : a) {
            for (int k = max(i - j.second, 0); k <= i - 1; k++) {
                dp[i] = min(dp[i], dp[k] + j.first);
            }
        }
    }
    cout << dp[c];
    return 0;
}
