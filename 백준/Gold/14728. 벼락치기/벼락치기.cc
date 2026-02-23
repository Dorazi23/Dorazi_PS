#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, k, need[105], score[105];
ll dp[10005];

void input () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> need[i] >> score[i];
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j-need[i] >= 0) dp[j] = max(dp[j], dp[j-need[i]] + score[i]);
        }
    }

    cout << dp[k] << endl;
}

int main() {
    fastio;
    input();
}