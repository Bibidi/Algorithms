#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    string upper = "";
    for (int i = 0; i < s.size(); i++) {
        upper += toupper(s[i]);
    }
    
    for (int i = 0; i < upper.size(); i++) {
        cnt[upper[i] - 'A']++;
    }
    
    int maxN = 0;
    char ans;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > maxN) {
            maxN = cnt[i];
            ans = (char) ('A' + i);
        }
        else if (cnt[i] == maxN) {
            ans = '?';
        }
    }
    cout << ans;
    return 0;
}
