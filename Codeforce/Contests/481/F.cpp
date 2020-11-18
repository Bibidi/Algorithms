#include <bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> skill(n);
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        cin >> skill[i];
        r[i].first = i;
        r[i].second = skill[i];
    }
    
    sort(r.begin(), r.end(), cmp);
    r[0].second = 0;
    for (int i = 1; i < n; i++) {
        if (skill[r[i].first] > skill[r[i-1].first])
            r[i].second = i;
        else
            r[i].second = r[i-1].second;
    }
    sort(r.begin(), r.end());
    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (skill[a] > skill[b]) {
            r[a].second--;
        }
        else if (skill[a] < skill[b]) {
            r[b].second--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << r[i].second << ' ';
    }
    return 0;
}
