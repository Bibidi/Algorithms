#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;

int n, m, k;
int money[10001];
int p[10001];

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    p[x] = y;
    int res = money[y];
    money[y] = min(money[x], money[y]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    money[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
        p[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += merge(0, i);
    }
    if (ans <= k) cout << ans;
    else cout << "Oh no";
    return 0;
}
