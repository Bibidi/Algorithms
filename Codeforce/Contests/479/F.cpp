#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, int> dp;
    
    int ans = 0;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        dp[x] = dp[x-1] + 1;
        if (dp[x] > ans) {
            ans = dp[x];
            lst = x;
        }
    }
    
    vector<int> res;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == lst) {
            res.push_back(i);
            lst--;
        }
    }
    reverse(res.begin(), res.end());
    
    cout << ans << '\n';
    for (int it : res)
        cout << it + 1 << ' ';
    return 0;
}
