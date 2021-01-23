#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tree[1 << 21];
int base, n;

void add(int k, int a) {
    k += base;
    tree[k] += a;
    for (k /= 2; k > 0; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int find(int k) {
    int pos = 1;
    while (pos < base) {
        if (tree[2 * pos] >= k) pos *= 2;
        else {
            k -= tree[2 * pos];
            pos = 2 * pos + 1;
        }
    }
    add(pos - base, -1);
    return pos - base;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (base = 1; base < 1000001; base *= 2);
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int c; cin >> c;
            cout << find(c) << '\n';
        }
        else {
            int f, c;
            cin >> f >> c;
            add(f, c);
        }
    }
}
