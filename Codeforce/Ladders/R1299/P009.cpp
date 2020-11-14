#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    
    bool nearly_lucky = true;
    int num_lucky = 0;
    
    for (char c : s) {
        if (c == '4' || c == '7') num_lucky++;
    }
    
    if (num_lucky == 0) nearly_lucky = false;
    else {
        while (num_lucky > 0) {
            int x = num_lucky % 10;
            if (x != 4 && x != 7)
                nearly_lucky = false;
            num_lucky /= 10;
        }
    }
    
    cout << (nearly_lucky ? "YES" : "NO");
    return 0;
}
