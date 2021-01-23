#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tree[1 << 20];
int base, n;
vector<int> a;

int sum(int a, int b) {
    a += base; b += base;
    int res = 0;
    while (a <= b) {
        if (a % 2 == 1) res += tree[a++];
        if (b % 2 == 0) res += tree[b--];
        a /= 2; b /= 2;
    }
    return res;
}

void erase(int k) {
    k += base;
    tree[k] = 0;
    for (k /= 2; k > 0; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (base = 1; base < n + 1; base *= 2);
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[t] = i;
    }
    for (int i = base + 1; i < base + n + 1; i++) {
        tree[i] = 1;
    }
    for (int i = base - 1; i > 0; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int t = (i + 1) / 2;
            int pos = a[t];
            erase(pos);
            cout << sum(1, pos - 1) << '\n';
        }
        else {
            int t = n - (i - 1) / 2;
            int pos = a[t];
            erase(pos);
            cout << sum (pos + 1, n) << '\n';
        }
    }
    return 0;
}
