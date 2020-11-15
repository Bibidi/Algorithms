#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    int res = 0;
    string ans;
    for (int i = 0; i < n-1; i++) {
        int cur = 0;
        for (int j = 0; j < n-1; j++) {
            if (s[i] == s[j] && s[i+1] == s[j+1])
                cur++;
        }
        if (cur > res) {
            res = cur;
            ans = s.substr(i, 2);
        }
    }
    cout << ans;
    return 0;
}
