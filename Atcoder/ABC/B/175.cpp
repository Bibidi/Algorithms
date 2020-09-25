#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] == a[j] || a[j] == a[k] || a[k] == a[i]) continue;
                if (a[i] < a[j] + a[k] && a[j] < a[i] + a[k] && a[k] < a[i] + a[j])
                    res++;
            }
        }
    }
    cout << res;
    
    return 0;
}
