#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    
    vector<int> cnt(26);
    
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    
    for (int i = 0; i < 26 && k > 0; i++) {
        if (k >= cnt[i]) {
            k -= cnt[i];
            cnt[i] = 0;
        }
        else {
            cnt[i] -= k;
            k = 0;
        }
    }
    
    stack<char> st;
    for (int i = n-1; i >= 0; i--) {
        char t = s[i];
        if (cnt[t - 'a'] > 0) {
            st.push(t);
            cnt[t - 'a']--;
        }
    }
    
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}
