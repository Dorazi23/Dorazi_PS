#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int n, d, answer;
vector<int> dp(10005, 10005);
vector<pair<int, int>> v[10005];

void input() {
    fastio; cin >> n >> d;
    while (n--) {
        int a, b, dist; cin >> a >> b >> dist;
        if (b-a <= dist) continue;
        if (b > d) continue;
        v[b].push_back({a, dist});
    }

    dp[0] = 0;
    
    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i-1] + 1;
        for (int j = 0; j < v[i].size(); j++) {
            // v[i][j].X: a
            // v[i][j].Y: dist
            // dp[i] = dp[v[i][j].X] + dp[i][j].Y
            dp[i] = min(dp[i], dp[v[i][j].X] + v[i][j].Y);
        }
    }

    cout << dp[d] << endl;
    
}

int main() {
    input();
}