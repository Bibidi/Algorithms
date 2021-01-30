#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    
    int n; cin >> n;
    vector<pair<double, double>> a(n + 2);
    for (int i = 1; i <= n; i++) {
        double y, x;
        cin >> y >> x;
        a[i] = {y, x};
    }
    a[0] = {sy, sx};
    a[n + 1] = {ey, ex};
    
    double t[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            double y2 = (a[i].first - a[j].first) * (a[i].first - a[j].first);
            double x2 = (a[i].second - a[j].second) * (a[i].second - a[j].second);
            double td = sqrt(y2 + x2);
            if (i == 0 || i == n + 1) t[i][j] = td / 5.0;
            else t[i][j] = min(td / 5.0, abs(td - 50.0) / 5.0 + 2.0);
            
        }
    }
    double time[n + 2];
    bool visited[n + 2];
    for (int i = 0; i < n + 2; i++) {
        time[i] = INF;
        visited[i] = false;
    }
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    time[0] = 0.0;
    q.push({0.0, 0});
    while (!q.empty()) {
        int cur = q.top().second; q.pop();
        if (visited[cur]) continue;
        
        visited[cur] = true;
        for (int i = 0; i < n + 2; i++) {
            int nxt = i;
            if (visited[nxt]) continue;
            double w = t[cur][nxt];
            if (time[cur] + w < time[nxt]) {
                time[nxt] = time[cur] + w;
                q.push({time[nxt], nxt});
            }
        }
    }
    cout << fixed << setprecision(6) << time[n + 1];
    return 0;
}
