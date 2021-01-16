#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<string> board;
int visited[50][50][1 << 6];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(visited, -1, sizeof(visited));
    cin >> n >> m;
    board = vector<string>(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    
    int sy = 0, sx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') {
                sy = i; sx = j;
            }
        }
    }
    
    int ans = -1;
    queue<tuple<int, int, int>> q;
    visited[sy][sx][0] = 0;
    q.push({sy, sx, 0});
    while (!q.empty()) {
        int y, x, bit;
        tie(y, x, bit) = q.front();
        q.pop();
        
        if (board[y][x] == '1') {
            ans = visited[y][x][bit];
            break;
        }
        
        if ('a' <= board[y][x] && board[y][x] <= 'z') {
            char key = board[y][x];
            int dist = visited[y][x][bit];
            bit |= (1 << (key - 'a'));
            visited[y][x][bit]= dist;
        }
        
        if ('A' <= board[y][x] && board[y][x] <= 'Z') {
            char key = board[y][x];
            if (!(bit & (1 << (key - 'A')))) continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == '#') continue;
            if (visited[ny][nx][bit] >= 0) continue;
            visited[ny][nx][bit] = visited[y][x][bit] + 1;
            q.push({ny, nx, bit});
        }
    }
    cout << ans;
    return 0;
}
