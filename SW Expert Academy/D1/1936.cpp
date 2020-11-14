#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    if ((a == 2 && b == 1) || (a == 3 && b == 2) || (a == 1 && b == 3))
        cout << "A";
    else
        cout << "B";
    
    return 0;
}
