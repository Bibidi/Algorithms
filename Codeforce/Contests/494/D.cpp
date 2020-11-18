#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int k = n / m;
    
    vector<int> a(n);
    vector<vector<int>> val(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        val[a[i] % m].push_back(i);
    }
    
    ll ans = 0;
    vector<pair<int, int>> fre;
    for (int i = 0; i < 2 * m; i++) {
        int cur = i % m;
        while (val[cur].size() > k) {
            int elem = val[cur].back();
            val[cur].pop_back();
            fre.push_back(make_pair(elem, i));
        }
        while (val[cur].size() < k && !fre.empty()) {
            int elem = fre.back().first;
            int mod = fre.back().second;
            fre.pop_back();
            val[cur].push_back(elem);
            a[elem] += i - mod;
            ans += i - mod;
        }
    }
    
    cout << ans << '\n';
    for (auto it : a) {
        cout << it << ' ';
    }
    return 0;
}
