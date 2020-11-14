#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    if (n % 2 == 1) cout << -1;
    else {
        for (int i = n; i >= 1; i--)
            cout << i << ' ';
    }
    return 0;
}
