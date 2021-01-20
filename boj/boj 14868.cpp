#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p[100001];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    p[x] = y;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) p[i] = i;
    int board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    int cnt = 0;
    queue<pair<int, int>> uq, wq;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cnt++;
        board[y][x] = cnt;
        uq.push({y, x});
    }
    
    int ans = 0;
    while (!uq.empty()) {
        while (!uq.empty()) {
            int y = uq.front().first;
            int x = uq.front().second;
            wq.push(uq.front());
            uq.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (board[ny][nx] == 0) continue;
                if (board[ny][nx] != board[y][x]) {
                    if (merge(board[ny][nx], board[y][x])) {
                        cnt--;
                    }
                }
            }
        }
        if (cnt == 1) {
            cout << ans;
            break;
        }
        while (!wq.empty()) {
            int y = wq.front().first;
            int x = wq.front().second;
            wq.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (board[ny][nx] == 0) {
                    board[ny][nx] = board[y][x];
                    uq.push({ny, nx});
                }
            }
        }
        ans++;
    }
    return 0;
}
