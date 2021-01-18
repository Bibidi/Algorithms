#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool visited[1000001];
int dp[1000001][2];
vector<vector<int>> a;

int solve(int cur, int colored) {
    if (dp[cur][colored] != -1) return dp[cur][colored];
    visited[cur] = true;
    int res = colored;
    for (int nxt : a[cur]) {
        if (visited[nxt]) continue;
        if (colored) res += min(solve(nxt, colored), solve(nxt, !colored));
        else res += solve(nxt, !colored);
    }
    visited[cur] = false;
    return dp[cur][colored] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    a = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout << min(solve(1, 0), solve(1, 1));
    return 0;
}
