#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;

int minT[1 << 20], maxT[1 << 20];
int base, n, m;

int pMin(int a, int b) {
    a += base; b += base;
    int res = INF;
    while (a <= b) {
        if (a % 2 == 1) res = min(res, minT[a++]);
        if (b % 2 == 0) res = min(res, minT[b--]);
        a /= 2; b /= 2;
    }
    return res;
}

int pMax(int a, int b) {
    a += base; b += base;
    int res = 0;
    while (a <= b) {
        if (a % 2 == 1) res = max(res, maxT[a++]);
        if (b % 2 == 0) res = max(res, maxT[b--]);
        a /= 2; b /= 2;
    }
    return res;
}

void update(int a, int b) {
    a += base; b += base;
    swap(minT[a], minT[b]);
    swap(maxT[a], maxT[b]);
    for (a /= 2; a > 0; a /= 2) {
        minT[a] = min(minT[2 * a], minT[2 * a + 1]);
        maxT[a] = max(maxT[2 * a], maxT[2 * a + 1]);
    }
    for (b /= 2; b > 0; b /= 2) {
        minT[b] = min(minT[2 * b], minT[2 * b + 1]);
        maxT[b] = max(maxT[2 * b], maxT[2 * b + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int test; cin >> test;
    while (test--) {
        cin >> n >> m;
        for (base = 1; base < n; base *= 2);
        for (int i = base; i < 2 * base; i++) {
            if (i < base + n) {
                minT[i] = maxT[i] = i - base;
            }
            else {
                minT[i] = INF;
                maxT[i] = 0;
            }
        }
        for (int i = base - 1; i > 0; i--) {
            minT[i] = min(minT[2 * i], minT[2 * i + 1]);
            maxT[i] = max(maxT[2 * i], maxT[2 * i + 1]);
        }
        
        for (int i = 0; i < m; i++) {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 0) update(a, b);
            else {
                int l = pMin(a, b);
                int r = pMax(a, b);
                if (l == a && r == b) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
