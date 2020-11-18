#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k; cin >> k;
    vector< pair<int, pair<int, int> > > a;
    for (int i = 0; i < k; i++) {
        int n; cin >> n;
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        
        int sum = accumulate(t.begin(), t.end(), 0);
        for (int j = 0; j < n; j++) {
            a.push_back(make_pair(sum - t[j], make_pair(i, j)));
        }
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i].first == a[i+1].first && a[i].second.first != a[i+1].second.first) {
            cout << "YES" << '\n';
            cout << a[i].second.first + 1 << ' ' << a[i].second.second + 1 << '\n';
            cout << a[i+1].second.first + 1 << ' ' << a[i+1].second.second + 1 << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}
