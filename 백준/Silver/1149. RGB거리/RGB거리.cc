#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define INF 0x4f4f4f4f
using namespace std;
int n, cost[1005][5], dp[1005][5];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) cin >> cost[i][j];
    }

    for (int i = 0; i < 1005; i++) fill (dp[i], dp[i]+5, INF);
    auto func = [&] (const auto& self, int idx, int pre) -> int {
        if (idx == n) return 0;
        
        int& ret = dp[idx][pre];
        if (ret != INF) return ret;
        
        if (pre == 1) { // 1, 2를 칠할 수 있음 
            ret = min({
                ret, 
                self(self, idx+1, 2) + cost[idx][2],
                self(self, idx+1, 3) + cost[idx][3],
            });
        }
        else if (pre == 2) {
            ret = min({
                ret, 
                self(self, idx+1, 1) + cost[idx][1],
                self(self, idx+1, 3) + cost[idx][3],
            });
        }
        else if (pre == 3) {
            ret = min({
                ret, 
                self(self, idx+1, 1) + cost[idx][1],
                self(self, idx+1, 2) + cost[idx][2],
            });
        }
        else { // 가장 처음 
            ret = min({
                ret, 
                self(self, idx+1, 1) + cost[idx][1],
                self(self, idx+1, 2) + cost[idx][2],
                self(self, idx+1, 3) + cost[idx][3],
            });
        }

        return ret;
    };

    cout << func(func, 0, 0) << endl;
}

int main() {
    fastio;
    input();
}