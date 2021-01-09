#include <bits/stdc++.h>
using namespace std;

#define y first
#define x second
typedef long long ll;

int n;
int a[20][20];

bool cut(pair<int, int> s, pair<int, int> e, int it, bool col) {
    int zem = 0;
    if (col) {
        for (int i = s.y; i <= e.y; i++) {
            if (a[i][it] == 2) zem++;
        }
    }
    else {
        for (int j = s.x; j <= e.x; j++) {
            if (a[it][j] == 2) zem++;
        }
    }
    return zem > 0 ? false : true;
}

int possible(pair<int, int> s, pair<int, int> e) {
    int trash = 0;
    int zem = 0;
    for (int i = s.y; i <= e.y; i++) {
        for (int j = s.x; j <= e.x; j++) {
            if (a[i][j] == 1) trash++;
            else if (a[i][j] == 2) zem++;
        }
    }
    if (zem == 0) return 0;
    else if (zem == 1 && trash == 0) return 1;
    else return 2;
}

// dir 0이면 가로로 자르고 1이면 세로로 자름.
int solve(pair<int, int> s, pair<int, int> e, int dir) {
    int p = possible(s, e);
    if (p == 0 || p == 1) return p;

    int ans = 0;
    if (dir == 0) {
        for (int i = s.y; i <= e.y; i++) {
            for (int j = s.x; j <= e.x; j++) {
                if (a[i][j] != 1) continue;
                if (cut(s, e, i, 0)) {
                    ans += solve(s, {i - 1, e.x}, 1) * solve({i + 1, s.x}, e, 1);
                }
            }
        }
    }
    else {
        for (int i = s.y; i <= e.y; i++) {
            for (int j = s.x; j <= e.x; j++) {
                if (a[i][j] != 1) continue;
                if (cut(s, e, j, 1)) {
                    ans += solve(s, {e.y, j - 1}, 0) * solve({s.y, j + 1}, e, 0);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    pair<int, int> start = {0, 0}, end = {n - 1, n -1};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 1) continue;
            if (cut(start, end, i, 0)) {
                ans += solve(start, {i - 1, end.x}, 1) * solve({i + 1, start.x}, end, 1);
            }
            if (cut(start, end, j, 1)) {
                ans += solve(start, {end.y, j - 1}, 0) * solve({start.y, j + 1}, end, 0);
            }
        }
    }
    if (ans == 0) cout << -1;
    else cout << ans;
    return 0;
}
