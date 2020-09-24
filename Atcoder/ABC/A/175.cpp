#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    int cnt = 0;
    int max_cnt = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            cnt++;
            max_cnt = cnt > max_cnt ? cnt : max_cnt;
        }
        else cnt = 0;
    }
    
    cout << max_cnt;
    return 0;
}
