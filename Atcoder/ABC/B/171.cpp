#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += a[i];
    }
    cout << res;
    
    return 0;
}
