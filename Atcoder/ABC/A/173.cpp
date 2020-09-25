#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    if (n % 1000 == 0) cout << 0;
    else cout << 1000 - n % 1000;
}
