#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<int> dist(n - 1);
    for (int i = 0; i < n - 1; i++) {
        dist[i] = a[i + 1] - a[i];
    }
    sort(dist.begin(), dist.end());
    
    int res = 0;
    for (int i = 0; i < n - k; i++) {
        res += dist[i];
    }
    cout << res;
    return 0;
}
