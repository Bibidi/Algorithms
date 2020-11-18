#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    double arr[n];
    double maxN = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxN = max(maxN, arr[i]);
    }
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / maxN * 100;
        sum += arr[i];
    }
    
    cout << sum / n;
    return 0;
}
