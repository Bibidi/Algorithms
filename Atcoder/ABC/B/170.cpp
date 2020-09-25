#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;
    
    bool res = false;
    for (int i = 0; i <= x; i++) {
        if (i * 2 + (x - i) * 4 == y)
            res = true;
    }
    cout << (res ? "Yes" : "No");
    return 0;
}
