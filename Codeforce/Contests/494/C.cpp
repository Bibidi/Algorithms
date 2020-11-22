#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    double ans = 0.0;
    for (int r = 1; r <= n; r++) {
        for (int l = 0; l < r; l++) {
            if (r - l >= k) {
                ans = max(ans, (a[r] - a[l]) / (double) (r - l));
            }
        }
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}
