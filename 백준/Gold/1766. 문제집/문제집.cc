#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
int deg[33000];
vector<int> adj[33000];
bool vis[33000];

void input () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        deg[b]++;
        adj[a].push_back(b);
    }

    // 큐에 들어간 값은 레벨이 동일함 (deg == 0)
    // 따라서, 그 안에서 오름차순 정렬된 값을 뽑아내야 함 -> 최소
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) { 
        if (deg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        // 현재 노드를 처리
        auto cur = pq.top(); pq.pop();
        cout << cur << " ";

        // 현재 노드와 이어진 노드들을 정리 
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) pq.push(nxt);
        }
    }
}

int main() {
    input();
}