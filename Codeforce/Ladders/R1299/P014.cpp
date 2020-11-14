#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int min_num = 101, max_num = 0;
    int min_idx, max_idx;
    
    for (int i = 0; i < n; i++) {
        if (a[i] <= min_num) {
            min_num = a[i];
            min_idx = i;
        }
        if (a[i] > max_num) {
            max_num = a[i];
            max_idx = i;
        }
    }
    
    int cnt = (n-1 - min_idx) + (max_idx);
    if (max_idx > min_idx)
        cout << cnt - 1;
    else
        cout << cnt;
    return 0;
}
