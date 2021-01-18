#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;

int mn[10001], mx[10001];
int sub[10001][2];
bool isRoot[10001];

// left_cnt는 왼쪽에 있지만 현 노드의 왼쪽 서브트리에 속하지 않은 노드의 개수
int solve(int cur, int left_cnt, int depth) {
    int cnt = 1;
    if (sub[cur][0] != -1) {
        cnt += solve(sub[cur][0], left_cnt, depth + 1);
    }
    mn[depth] = min(mn[depth], cnt + left_cnt);
    mx[depth] = max(mx[depth], cnt + left_cnt);
    if (sub[cur][1] != -1) {
        cnt += solve(sub[cur][1], cnt + left_cnt, depth + 1);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        isRoot[i] = true;
        mn[i] = INF;
        mx[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        int root, left, right;
        cin >> root >> left >> right;
        sub[root][0] = left;
        sub[root][1] = right;
        if (left != -1) isRoot[left] = false;
        if (right != -1) isRoot[right] = false;
    }
    
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i]) start = i;
    }
    
    solve(start, 0, 1);
    int ans_depth = 0, ans_width = 0;
    for (int i = 1; i <= n; i++) {
        if (mx[i] == 0) break;
        int width = mx[i] - mn[i] + 1;
        if (width > ans_width) {
            ans_width = width;
            ans_depth = i;
        }
    }
    
    cout << ans_depth << '\n' << ans_width;
    return 0;
}
