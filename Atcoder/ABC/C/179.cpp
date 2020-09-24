#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin >> N;
    int cnt = 0;
    
    for (long a = 1; a <= N; a++) {
        for (long b = a; a * b < N; b++) {
            if (a == b) cnt++;
            else cnt += 2;
        }
    }
    
    cout << cnt;
    return 0;
}
