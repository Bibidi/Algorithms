#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;

int n, m, ans = INF;
int board[50][50];
int dist[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void solve(int cur, int k) {
    if (k == m) {
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        for (auto nxt : selected) {
            q.push({nxt.first, nxt.second});
            dist[nxt.first][nxt.second] = 0;
        }
        
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (dist[ny][nx] >= 0) continue;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) sum += dist[i][j];
            }
        }
        ans = min(ans, sum);
        return;
    }
    if (cur >= chicken.size()) return;
    selected.push_back(chicken[cur]);
    solve(cur + 1, k + 1);
    selected.pop_back();
    solve(cur + 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    solve(0, 0);
    cout << ans;
    return 0;
}
