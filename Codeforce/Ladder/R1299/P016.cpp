#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int d[4], n;
    for (int i = 0; i < 4; i++)
        cin >> d[i];
    cin >> n;
    
    bool a[n+1];
    for (int i = 0; i <= n; i++)
        a[i] = false;
    
    for (int i = 0; i < 4; i++)
        for (int j = d[i]; j <= n; j += d[i])
            a[j] = true;
    
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (a[i]) res++;
    
    cout << res;
    
    return 0;
}
