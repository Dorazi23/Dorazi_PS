#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define  INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m, k, arr[100][100];
int px, py;
int dp[100][100];

int main() {
    memset(dp, 0, sizeof(dp));
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <=  n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    if(k == 0){
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(dp[i][j] != 0) continue;
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
            }
        }
        cout << dp[n][m] << endl;
        return 0;
    }

    px = (k - 1) / m + 1;
    py = (k - 1) % m + 1;
    dp[1][1] = 1;
    for (int i = 1; i <= px; i++) {
        for (int j = 1; j <= py; j++) {
            if(dp[i][j] != 0) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
    }
    for (int i = px; i <= n; i++) {
        for (int j = py; j <= m; j++) {
            if(dp[i][j] != 0) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
}