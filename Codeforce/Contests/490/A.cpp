#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    deque<int> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back(t);
    }
    
    int cnt = 0;
    while (!a.empty() && (a.front() <= k || a.back() <= k)) {
        if (a.front() <= k) {
            a.pop_front();
            cnt++;
        }
        else if (a.back() <= k) {
            a.pop_back();
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
