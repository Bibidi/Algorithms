#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 1;

bool marked[N];
vector<int> g[N];
bool degree;
 
void dfs(int v) {
    marked[v] = true;
    if (g[v].size() != 2)
        degree = false;
    
    for (int w : g[v]) {
        if (!marked[w]) {
            dfs(w);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(marked, 0, sizeof(marked));
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int cycle = 0;
    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            degree = true;
            dfs(i);
            if (degree) cycle++;
        }
    }
    cout << cycle;
    return 0;
}
