#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int cnt = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a * b < n) cnt++;
            else break;
        }
    }
    cout << cnt;
    return 0;
}
