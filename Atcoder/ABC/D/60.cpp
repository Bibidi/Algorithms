#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, W, w[100];
    cin >> n >> W;
    
    vector<ll> val[4];
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> w[i] >> v;
        val[w[i] - w[0]].push_back(v);
    }
    
    for (int i = 0; i < 4; i++) {
        sort(val[i].begin(), val[i].end(), greater<int>());
        val[i].insert(val[i].begin(), 0);
        
        for (int j = 1; j < val[i].size(); j++) {
            val[i][j] += val[i][j-1];
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < val[0].size(); i++) {
        for (int j = 0; j < val[1].size(); j++) {
            for (int k = 0; k < val[2].size(); k++) {
                for (int l = 0; l < val[3].size(); l++) {
                    ll wei = w[0] * (i + j + k + l);
                    wei += j + 2 * k + 3 * l;
                    if (wei <= W) {
                        ans = max(ans, val[0][i] + val[1][j] + val[2][k] + val[3][l]);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
