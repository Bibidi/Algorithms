#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "AC") a++;
        else if (s == "WA") b++;
        else if (s == "TLE") c++;
        else if (s == "RE") d++;
    }
    
    cout << "AC x " << a << '\n';
    cout << "WA x " << b << '\n';
    cout << "TLE x " << c << '\n';
    cout << "RE x " << d << '\n';
    
    return 0;
}
