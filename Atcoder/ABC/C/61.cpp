#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll arr[100001];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(arr, 0, sizeof(arr));
    ll n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] += b;
    }
    
    ll num = 0;
    for (int i = 1; i <= 100000; i++) {
        num += arr[i];
        if (num >= k) {
            cout << i;
            break;
        }
    }
    return 0;
}
