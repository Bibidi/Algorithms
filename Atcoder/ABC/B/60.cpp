#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    string ans = "NO";
    for (int i = 1; i <= b; i++) {
        if ((a * i) % b == c) {
            ans = "YES";
            break;
        }
    }
    cout << ans;
    
    return 0;
}
