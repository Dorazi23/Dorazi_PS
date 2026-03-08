#include <bits/stdc++.h>
using namespace std;
int n, L[105], J[105], dp[105];

void input () {
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> L[i];
    for (int i = 0; i < n; i++) cin >> J[i];

    for (int i = 0; i < n; i++) {
        for (int k = 100; k >= 0; k--) {
            if (k - L[i] > 0) {
                dp[k] = max(dp[k], dp[k-L[i]] + J[i]);
            }
        }
    }

    int res = -100;
    for (int i = 100; i >= 0; i--) res = max(res, dp[i]);

    cout << res << endl;
}

int main() {
    input();
}