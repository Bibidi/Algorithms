#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, x;
    cin >> a >> b >> x;
    
    if (x % 2 == 0) {
        if (a > b) {
            for (int i = 0; i < x/2; i++) {
                cout << "01";
            }
            cout << string(b - x/2, '1');
            cout << string(a - x/2, '0');
        }
        else {
            for (int i = 0; i < x/2; i++) {
                cout << "10";
            }
            cout << string(a - x/2, '0');
            cout << string(b - x/2, '1');
        }
    }
    else {
        if (a > b) {
            for (int i = 0; i < x/2; i++) {
                cout << "01";
            }
            cout << string(a - x/2, '0');
            cout << string(b - x/2, '1');
        }
        else {
            for (int i = 0; i < x/2; i++) {
                cout << "10";
            }
            cout << string(b - x/2, '1');
            cout << string(a - x/2, '0');
        }
    }
    return 0;
}

