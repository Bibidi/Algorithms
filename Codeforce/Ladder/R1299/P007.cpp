#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    int num_lower = 0;
    int num_upper = 0;
    
    for (char c : s) {
        if (islower(c)) num_lower++;
        else num_upper++;
    }
    
    bool print_upper = num_upper > num_lower ? true : false;
    for (char c : s)
        cout << (char) (print_upper ? toupper(c) : tolower(c));
    
    return 0;
}
