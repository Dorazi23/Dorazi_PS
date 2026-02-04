#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e18
using namespace std;
using ll = long long;
int n, m;
vector<int> p(100005, -1), adj[100005];
ll dp[100005];

void input () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        p[i] = v;
        if (v != -1) {
            adj[i].push_back(v);
            adj[v].push_back(i);   
        }
    }
    while (m--) {
        int i, w; cin >> i >> w;
        dp[i] += w;
    }

    dp[1] = 0;
    auto ret = [&] (const auto& self, int cur) -> void {
        for (auto nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            dp[nxt] += dp[cur];
            self(self, nxt);   
        }
    };

    ret(ret, 1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}

int main() {
    fastio;
    input();
}