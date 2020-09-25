#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    long res[4];
    res[0] = a * c;
    res[1] = a * d;
    res[2] = b * c;
    res[3] = b * d;
    
    long max = res[0];
    for (int i = 1; i < 4; i++) {
        max = res[i] > max ? res[i] : max;
    }
    cout << max;
    
    return 0;
}
