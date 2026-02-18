#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, sum[505], dp[505][505];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) { // 누적합
        int m; cin >> m;
        if (i == 0) sum[i] = m;
        else sum[i] = sum[i-1] + m;
    }

    for (int len = 1; len < n; len++) { // 구간의 길이 
        for (int x = 0;  x + len < n; x++) { // 구간의 시작 idx
            int y = x + len;
            dp[x][y] = INF;

            for (int md = x; md < y; md++) { // 구간을 나누는 idx
                int tot = x > 0 ? sum[y] - sum[x-1] : sum[y];
                dp[x][y] = min(dp[x][y], dp[x][md] + dp[md+1][y] + tot);
            }
        }
    }

    cout << dp[0][n-1] << endl;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        input();   
    }
}