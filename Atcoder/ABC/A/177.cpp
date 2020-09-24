#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int d, t, s;
    cin >> d >> t >> s;
    
    if ((d + s - 1) / s <= t) cout << "Yes";
    else cout << "No";
    
    return 0;
}
