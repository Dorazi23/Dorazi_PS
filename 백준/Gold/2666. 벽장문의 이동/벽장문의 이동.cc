#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
int n, m, a, b, arr[1005];
int res;

int dp[25][25][25];

void input () {
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 25; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    
    // func(idx, u, v) = idx번째 요청까지 처리하고 열린 문이 u, v일때 이동 횟수 
    auto func = [&] (const auto& self, int idx, int u, int v) -> int {
        if (idx == m) return 0;

        int& ret = dp[idx][u][v];
        if (ret != INF) return ret;

        ret = min(
            self(self, idx+1, arr[idx], v) + abs(u-arr[idx]),
            self(self, idx+1, u, arr[idx]) + abs(v-arr[idx])
        );

        return ret;
    };

    cout << func(func, 0, a, b) << endl;
}

int main() {
    fastio;
    input();
}