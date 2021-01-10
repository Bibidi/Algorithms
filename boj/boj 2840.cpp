#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = '?';
    }
    
    int cur = 0;
    for (int i = 0; i < k; i++) {
        int cnt; char c;
        cin >> cnt >> c;
        
        cur = (cur - cnt + 100 * n) % n;
        if (s[cur] != '?' && s[cur] != c) {
            cout << "!";
            return 0;
        }
        else s[cur] = c;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] != '?' && s[i] == s[j]) {
                cout << "!";
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << s[(cur + i) % n];
    }
    return 0;
}

