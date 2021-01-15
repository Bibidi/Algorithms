#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;

int n, k;

void setDigit(int &bit, int k, int num) {
    for (int i = 0; i < 3; i++) {
        bit &= ~(1 << (3 * k + i));
        if (num & (1 << i))
            bit |= (1 << (3 * k + i));
    }
}

int getDigit(int &bit, int k) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (bit & (1 << (3 * k + i)))
            sum += (1 << i);
    }
    return sum;
}

void swapDigit(int &bit, int pos1, int pos2) {
    int a = getDigit(bit, pos1);
    int b = getDigit(bit, pos2);
    setDigit(bit, pos2, a);
    setDigit(bit, pos1, b);
}

void swapDigitRange(int &bit, int s, int e) {
    while (s < e) {
        swapDigit(bit, s, e);
        s++; e--;
    }
}

void print(int bit) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            if (bit & (1 << (3 * i + j)))
                sum += (1 << j);
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        setDigit(start, i, t - 1);
    }
    
    int target = 0;
    for (int i = 0; i < n; i++) {
        setDigit(target, i, i);
    }
    
    int ans = INF;
    set<int> du;
    du.insert(start);
    queue<pair<int, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (cur == target) {
            ans = dist;
            break;
        }
        
        for (int i = 0; i < n - k + 1; i++) {
            swapDigitRange(cur, i, i + k - 1);
            if (!du.count(cur)) {
                du.insert(cur);
                q.push({cur, dist + 1});
            }
            swapDigitRange(cur, i, i + k - 1);
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}
