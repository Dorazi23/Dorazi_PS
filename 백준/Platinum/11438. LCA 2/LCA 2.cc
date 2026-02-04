#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
const int sz = 1e5+10;
vector<int> adj[sz];
int n, depth[sz], vis[sz], dp[sz][35];
// dp[i][j]: i 번째 노드의 2^j 번째 조상

void dfs (int cur, int d) {
    vis[cur] = 1;
    depth[cur] = d;

    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dp[nxt][0] = cur;
        dfs (nxt, d+1);
    }
}

void make_table () {
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int LCA (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++) { // diff 차이만큼 노드 u를 올림 
        if (diff & 1) u = dp[u][i]; // 2^i 칸 만큼 점프
        diff >>= 1;
    }

    // 한 노드가 다른 노드의 조상인 경우
    if (u == v) return u;

    // LCA 직전까지 두 노드를 끌어 올림
    for (int i = 29; i >= 0; i--) {
        // LCA 보다 더 깊은 경우 공통 조상이 존재하지 않음 
        // 따라서, 2^i번 째 조상이 서로 다르고 그 만큼 점프한다는 건 LCA에 가까워짐을 의미 
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    // LCA 직전까지 두 노드가 이동했으므로, 아무거나 한 칸 위로 올리면 LCA
    return dp[u][0];
}

void input () {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs (1, 0);
    make_table();

    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        cout << LCA (u, v) << endl;
    }
}

int main() {
    fastio;
    input();
}