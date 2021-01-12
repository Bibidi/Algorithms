#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, cnt;
int nxt[1001];
bool visited[1001];
int done[1001];
int cycle[1001];

int dfs(int cur) {
    visited[cur] = true;
    if (!visited[nxt[cur]]) {
        return done[cur] = dfs(nxt[cur]);
    }
    else if (done[nxt[cur]] == 0) {
        cnt++;
        cycle[cur] = cnt;
        for (int node = nxt[cur]; node != cur; node = nxt[node]) {
            cycle[node] = cnt;
        }
        return done[cur] = cnt;
    }
    else return done[cur] = done[nxt[cur]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    
    vector<pair<int, int>> component(cnt + 1);
    for (int i = 1; i <= n; i++) {
        component[cycle[i]].first++;
        component[done[i]].second++;
    }
    
    bool dt[k + 1];
    memset(dt, 0, sizeof(dt));
    dt[0] = true;
    for (int i = 1; i <= cnt; i++) {
        for (int j = k; j >= 0; j--) {
            for (int w = component[i].first; w <= component[i].second; w++) {
                if (j >= w) {
                    dt[j] |= dt[j - w];
                }
            }
        }
    }
    
    for (int i = k; i >= 0; i--) {
        if (dt[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
