#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    bool first = true;
    for (char c : s) {
        if (first) {
            cout << (char) toupper(c);
            first = false;
        }
        else cout << c;
    }
    return 0;
}
