#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int count3(ll x) {
    int cnt = 0;
    while (x % 3 == 0) {
        x /= 3;
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, ll>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
        v[i].first = -count3(v[i].second);
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        cout << v[i].second << ' ';
    }
    return 0;
}
