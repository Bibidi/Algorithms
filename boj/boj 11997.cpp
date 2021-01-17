#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    set<int> visitX, visitY;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        visitY.insert(a[i].first);
        visitX.insert(a[i].second);
    }
    
    vector<int> posX, posY;
    for (int x : visitX) posX.push_back(x);
    for (int y : visitY) posY.push_back(y);
    
    int board[posY.size()][posX.size()];
    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++) {
        int y = (int) (lower_bound(posY.begin(), posY.end(), a[i].first) - posY.begin());
        int x = (int) (lower_bound(posX.begin(), posX.end(), a[i].second) - posX.begin());
        board[y][x]++;
    }
    
    int psum[posY.size() + 1][posX.size() + 1];
    memset(psum, 0, sizeof(psum));
    for (int i = 0; i < posY.size(); i++) {
        for (int j = 0; j < posX.size(); j++) {
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + board[i][j];
        }
    }
    
    int ans = n;
    for (int i = 1; i <= posY.size(); i++) {
        for (int j = 1; j <= posX.size(); j++) {
            int one = psum[i - 1][j - 1];
            int two = psum[i - 1][posX.size()] - one;
            int three = psum[posY.size()][j - 1] - one;
            int four = n - two - three - one;
            
            int mx = max(one, max(two, max(three, four)));
            ans = min(ans, mx);
        }
    }
    cout << ans;
    return 0;
}
