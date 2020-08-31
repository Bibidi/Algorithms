#include <bits/stdc++.h>
using namespace std;

int light[3][3];
int dy[5] = {-1, 0, 0, 0, 1};
int dx[5] = {0, -1, 0, 1, 0};

void toggle(int y, int x, bool b) {
    if (b == false) return;
    for (int next = 0; next < 5; next++) {
        int ny = y + dy[next];
        int nx = x + dx[next];
        if (ny < 0 || ny > 2 || nx < 0 || nx > 2) continue;
        light[ny][nx] = 1 - light[ny][nx];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // init
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            light[i][j] = 1;
        }
    }
    
    // input + toggle
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            toggle(i, j, x % 2 == 1);
        }
    }
    
    // output
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << light[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
