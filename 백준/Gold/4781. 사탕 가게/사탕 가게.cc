#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int c[5005], dp[10005]; double p[5005];

// 사탕을 살지 말지를 결정하므로, 부분 집합 문제 -> 쪼갤 수 없으므로 dp
void input () {
    while (true) {
        fill (c, c+5005, 0); fill (p, p+5005, 0.00); fill (dp, dp+10005, 0);
        
        int n; double m; cin >> n >> m;
        if (n == 0 && m == 0.00) break;
        for (int i = 0; i < n; i++) cin >> c[i] >> p[i];

        for (int i = 0; i < n; i++) {
            int calorie = c[i];
            int price = (int)(p[i] * 100 + 0.5);

            for (int k = 0; k <= (int)(m*100 + 0.5); k++) {
                if (k-price >= 0) dp[k] = max(dp[k], dp[k-price] + calorie);
            }
        }

        int idx = (int)(m * 100 + 0.5);
        cout << dp[idx] << endl;
    }
}

int main() {
    fastio;
    input();
}