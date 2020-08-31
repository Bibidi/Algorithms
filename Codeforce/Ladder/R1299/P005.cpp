#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int year; cin >> year;
    for (int next = year + 1; next <= 10000; next++) {
        int a, b, c, d;
        a = next / 1000;
        b = (next % 1000) / 100;
        c = (next % 100) / 10;
        d = next % 10;
        
        if (a != b && a != c && a != d &&
            b != c && b != d &&
            c != d) {
            cout << next;
            break;
        }
    }
    return 0;
}
