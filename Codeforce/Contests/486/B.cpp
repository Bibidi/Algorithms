#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end(), [&] (const string &a, const string &b) {
        return a.size() < b.size();
    });
        
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (s[i].find(s[i-1]) == string::npos) {
            ok = false;
            break;
        }
    }
        
    if (ok) {
        cout << "YES" << '\n';
        for (string t : s)
            cout << t << '\n';
    }
    else {
        cout << "NO";
    }
    return 0;
}
