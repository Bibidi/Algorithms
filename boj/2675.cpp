#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test; cin >> test;
    for (int i = 0; i < test; i++) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
