#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b, c;
    cin >> a >> b >> c;
    
    if (a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0])
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
