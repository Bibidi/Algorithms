#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, dir[4];
bool visited[31][31];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

double solve(int y, int x, int dist) {
    if (dist == n) return 1.0;
    visited[y][x] = true;
    double res = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!visited[ny][nx]) {
            res += dir[i] * solve(ny, nx, dist + 1) / 100;
        }
    }
    visited[y][x] = false;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> dir[2] >> dir[0] >> dir[3] >> dir[1];
    cout << fixed;
    cout << setprecision(15) << solve(15, 15, 0);
    return 0;
}

