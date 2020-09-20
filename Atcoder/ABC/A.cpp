#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    if (s[s.length() - 1] == 's') {
        cout << s + "es";
    }
    else {
        cout << s + "s";
    }
    
    return 0;
}
