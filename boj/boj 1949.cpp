#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p[10001];
int dp[10001][2];
bool visited[10001];
vector<vector<int>> a;

int solve(int cur, int isGood) {
    if (dp[cur][isGood] != -1) return dp[cur][isGood];
    visited[cur] = true;
    int res = (isGood ? p[cur] : 0);
    for (int nxt : a[cur]) {
        if (visited[nxt]) continue;
        if (isGood) res += solve(nxt, !isGood);
        else res += max(solve(nxt, isGood), solve(nxt, !isGood));
    }
    visited[cur] = false;
    return dp[cur][isGood] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    a = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout << max(solve(1, 0), solve(1, 1));
    return 0;
}
