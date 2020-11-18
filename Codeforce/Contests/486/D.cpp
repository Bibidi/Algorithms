#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    
    vector<int> ans = { x[0] };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            int lx = x[i] - (1 << j);
            int rx = x[i] + (1 << j);
            bool isl = binary_search(x.begin(), x.end(), lx);
            bool isr = binary_search(x.begin(), x.end(), rx);
            if (isl && isr && ans.size() < 3) {
                ans = {lx, x[i], rx};
            }
            else if (isl && ans.size() < 2) {
                ans = {lx, x[i]};
            }
            else if (isr && ans.size() < 2) {
                ans = {x[i], rx};
            }
        }
    }
    
    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';
    return 0;
}
