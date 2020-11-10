#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> r[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << r[i].size() << '\n';
    }
    return 0;
}
