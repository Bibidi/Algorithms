#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) cout << 0;
        else cout << 1;
    }
    
    return 0;
}
