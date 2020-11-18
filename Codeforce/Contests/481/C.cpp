#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> dor(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> dor[i];
        dor[i] += dor[i-1];
    }
    
    for (int i = 0; i < m; i++) {
        ll t; cin >> t;
        
        int st = 1, ed = n;
        while (st < ed) {
            int mid = (st + ed) / 2;
            if (dor[mid] >= t) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        cout << st << ' ' << t - dor[st-1] << '\n';
    }
    return 0;
}
