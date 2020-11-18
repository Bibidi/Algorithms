#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    set<int> exist;
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (exist.find(t) == exist.end()) {
            exist.insert(t);
            ans.push_back(i);
            cnt++;
        }
    }
    if (cnt >= k) {
        cout << "YES" << '\n';
        for (int i = 0; i < k; i++)
            cout << ans[i] << ' ';
    }
    else
        cout << "NO";
    return 0;
}
