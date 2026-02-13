#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n, m, arr[100005], dp[100005];

void input () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    while (m --) {
        int u, v; cin >> u >> v;
        if (u == 1) cout << dp[v] << endl;
        else cout << dp[v] - dp[u-1] << endl;
    }
}

int main() {
    fastio;
    input();
}