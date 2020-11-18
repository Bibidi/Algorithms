#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    set<int> exist;
    vector<int> ans;
    for (int i = n-1; i >= 0; i--) {
        if (exist.find(a[i]) == exist.end()) {
            exist.insert(a[i]);
            ans.push_back(a[i]);
        }
    }
    
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    return 0;
}
