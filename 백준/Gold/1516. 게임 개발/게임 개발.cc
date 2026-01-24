#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, Time[505], deg[505];
ll dp[505];
vector<int> adj[505];

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Time[i];
        int m;
        while (cin >> m) {
            if (m == -1) break;
            deg[i]++;
            adj[m].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            dp[i] = Time[i];
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + Time[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }
}

int main() {
    fastio;
    input();
}