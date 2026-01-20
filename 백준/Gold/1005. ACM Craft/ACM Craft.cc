#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k, w;
int deg[1005];
int buildTime[1005];
int dp[1005]; 

void input() {
    memset(dp, 0, sizeof(dp));
    memset(deg, 0, sizeof(deg));
    memset(buildTime, 0, sizeof(buildTime));
    vector<int> adj[1005];
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> buildTime[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    cin >> w;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            dp[i] = buildTime[i];
            q.push(i);
        } 
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur == w) {
            cout << dp[cur] << endl;
            return;
        }
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + buildTime[nxt]);
            if (deg[nxt] == 0) { // 지을 수 있음 
                q.push(nxt);
            }
        }
    }
    
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        input();
    }
}