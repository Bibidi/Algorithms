#include <bits/stdc++.h>
using namespace std;

bool is_prime[51];

void erathos() {
    for (int i = 2; i <= 50; i++)
        is_prime[i] = true;
    
    for (int i = 2; i <= 50; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 50; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    erathos();
    int n, m; cin >> n >> m;
    bool next_prime = true;
    
    for (int i = n + 1; i < m; i++) {
        if (is_prime[i])
            next_prime = false;
    }
    
    cout << (next_prime && is_prime[m] ? "YES" : "NO");
    
    return 0;
}
