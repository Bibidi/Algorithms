#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pos;
vector<int> pre, in;

void solve(int l, int r) {
    if (l > r) return;
    int root = pre[pos++];
    int idx = 0;
    while (in[idx] != root) idx++;
    solve(l, idx - 1);
    solve(idx + 1, r);
    cout << root << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int test; cin >> test;
    while (test--) {
        pos = 0;
        int n; cin >> n;
        pre = vector<int>(n);
        in = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        solve(0, n - 1);
        cout << '\n';
    }
    return 0;
}
