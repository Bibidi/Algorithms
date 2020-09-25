#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    
    int max = 0;
    for (int i = 0; i < s.length() - t.length() + 1; i++) {
        int same = 0;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] == t[j]) same++;
        }
        max = same > max ? same : max;
    }
    cout << t.length() - max;
    return 0;
}
