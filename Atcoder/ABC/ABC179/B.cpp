#include <bits/stdc++.h>
using namespace std;
 
bool doublet[100];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        doublet[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a == b) {
            doublet[i] = true;
        }
    }
    
    bool res = false;
    for (int i = 0; i < n - 2; i++) {
        if (doublet[i] && doublet[i+1] && doublet[i+2]) {
            res = true;
            break;
        }
    }
    
    cout << (res ? "Yes" : "No");
    
    return 0;
}
