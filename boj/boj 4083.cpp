#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> a;
bool visited[500];

void print(int test, int cnt) {
    cout << "Case " << test << ": ";
    if (cnt == 0) cout << "No trees.";
    else if (cnt == 1) cout << "There is one tree.";
    else cout << "A forest of " << cnt << " trees.";
    cout << '\n';
}

bool solve(int cur, int prior) {
    visited[cur] = true;
    bool ok = true;
    for (int nxt : a[cur]) {
        if (!visited[nxt]) {
            ok &= solve(nxt, cur);
        }
        else if (nxt != prior) {
            ok = false;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int test = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        
        memset(visited, 0, sizeof(visited));
        a = vector<vector<int>>(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool isTree = solve(i, -1);
                if (isTree) cnt++;
            }
        }
        print(test++, cnt);
    }
    return 0;
}
