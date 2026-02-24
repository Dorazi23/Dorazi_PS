#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, a, b;
vector<pair<int,int>> adj[100005];
ll dist1[100005], dist2[100005], answer = 4e18;

void bfs (int root, ll dist[]) { // 로봇의 위치
    fill (dist, dist+100005, -1);
    queue<int> q;
    q.push(root);
    dist[root] = 0; 

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) { // {노드, 거리}
            if (dist[nxt.X] != -1) continue;
            dist[nxt.X] = dist[cur] + nxt.Y;
            q.push(nxt.X);
        }
    }
}

void input () {
    cin >> n >> a >> b;
    if (a == b) { // 두 로봇이 같은 노드에 있을 때 
        cout << "0" << endl;
        return;
    }
    
    for (int i = 0; i < n-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    bfs(a, dist1);
    bfs(b, dist2);

    for (int u = 1; u <= n; u++) { // 노드 u
        for (auto v : adj[u]) { // 노드 u와 연결된 노드 v 
            // 더 가까운 거리를 택하기
            if (dist1[u] < dist1[v.X]) {
                answer = min(answer, dist1[u] + dist2[v.X]);
            }
            else {
                answer = min(answer, dist1[v.X] + dist2[u]);
            }
        }
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}