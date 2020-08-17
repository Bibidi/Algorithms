#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    
    for (int i = 0; i < n; i++) {
        int _x = 0, _y = 0, _z = 0;
        cin >> _x >> _y >> _z;
        x += _x;
        y += _y;
        z += _z;
    }
    
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}
