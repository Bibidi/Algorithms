#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;

struct st {
    int x, y, z;
};

bool cmp(st a, st b) {
    return a.x < b.x;
}

int tree[1 << 21];
int base, n;

int pMin(int a, int b) {
    a += base; b += base;
    int res = INF;
    while (a <= b) {
        if (a % 2 == 1) res = min(res, tree[a++]);
        if (b % 2 == 0) res = min(res, tree[b--]);
        a /= 2; b /= 2;
    }
    return res;
}

void update(int k, int b) {
    k += base;
    tree[k] = b;
    for (k /= 2; k > 0; k /= 2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    vector<st> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[t].x = i;
    }
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[t].y = i;
    }
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[t].z = i;
    }
    sort(a.begin() + 1, a.end(), cmp);
    
    for (base = 1; base < n + 1; base *= 2);
    for (int i = base; i <= base + n; i++) {
        tree[i] = INF;
    }
    for (int i = base - 1; i > 0; i--) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int m = pMin(0, a[i].y - 1);
        if (a[i].z < m) ans++;
        update(a[i].y, a[i].z);
    }
    cout << ans;
    return 0;
}
