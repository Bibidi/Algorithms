#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(101);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a[t]++;
    }
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}
