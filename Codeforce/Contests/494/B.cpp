#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(s.begin(), s.begin() + i);
        }
    }
    cout << s << '\n';
    return 0;
}
