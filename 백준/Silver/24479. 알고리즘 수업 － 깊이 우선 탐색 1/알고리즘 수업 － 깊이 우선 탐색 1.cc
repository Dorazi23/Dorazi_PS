#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, r;
vector<int> adj[100005];
int answer[100005];
bool vis[100005];
int ans = 1;

void dfs (int cur, int& cnt) {
    if (vis[cur]) return;
    vis[cur] = 1;
    answer[cur] = cnt;
    sort(adj[cur].begin(), adj[cur].end());
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        cnt++;
        dfs(nxt, cnt);
    }
}

int main() {
    fastio;
    cin >> n >> m >> r;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r, ans);

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << endl;
    }
}