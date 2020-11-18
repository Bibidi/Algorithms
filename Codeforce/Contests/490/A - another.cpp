#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back(t);
    }
    
    int cnt = 0;
    while (!a.empty() && a.back() <= k) {
        cnt++;
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() <= k) {
        cnt++;
        a.pop_back();
    }
    cout << cnt << '\n';
    return 0;
}
