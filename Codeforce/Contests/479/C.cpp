#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    
    if (k == 0) {
        if (arr[k] > 1)
            cout << 1;
        else
            cout << -1;
    }
    else if (k == n)
        cout << arr[k-1];
    else {
        if (arr[k-1] != arr[k])
            cout << arr[k-1];
        else
            cout << -1;
    }
    return 0;
}
