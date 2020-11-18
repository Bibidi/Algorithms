#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
    
    int cnt = 0;
    int suc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') suc++;
        else suc = 0;
        
        if (suc > 2) cnt++;
    }
    cout << cnt;
    return 0;
}
