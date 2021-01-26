#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll ans = 0;
void solve(int cur, ll sum) {
    if (cur == s.size()) {
        if (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0 || sum % 7 == 0) ans++;
        return;
    }
    ll nxt = 0;
    for (int i = cur; i < s.size(); i++) {
        nxt *= 10;
        nxt += s[i] - '0';
        
        solve(i + 1, sum + nxt);
        if (cur != 0) {
            solve(i + 1, sum - nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int test; cin >> test;
    for (int i = 1; i <= test; i++) {
        cin >> s;
        ans = 0;
        solve(0, 0);
        cout << "Case #" << i << ": " << ans << '\n';
    }
    return 0;
}
