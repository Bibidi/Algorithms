#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int ans;
    if (k == 0) {
        ans = arr[0] - 1;
    }
    else {
        ans = arr[k-1];
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= ans)
            cnt++;
    }
    
    if (cnt != k || !(1 <= ans && ans <= 1000 * 1000 * 1000))
        ans = -1;
    
    cout << ans;
    return 0;
}
