#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<char, ll>> a;
vector<vector<int>> e;

ll solve(int cur) {
    ll res = (a[cur].first == 'S' ? a[cur].second : 0);
    for (int nxt : e[cur]) {
        res += solve(nxt);
    }
    if (a[cur].first == 'W') res = max(res - a[cur].second, 0LL);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    a = vector<pair<char, ll>>(n + 1);
    e = vector<vector<int>>(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        int p; cin >> p;
        e[p].push_back(i);
    }
    cout << solve(1);
    return 0;
}
