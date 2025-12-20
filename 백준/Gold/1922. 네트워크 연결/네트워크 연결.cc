#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int n, m;
tuple<int,int,int> edge[100005];
vector<int> p(10005, -1);

int Find (int x) {
    if (p[x] < 0) return x;
    return x = Find(p[x]);
}

bool Union (int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

void input() {
    fastio; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge, edge + m);
    
    int answer = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        auto [cost, a, b] = edge[i];
        if (!Union(a, b)) continue;
        answer += cost;
        cnt++;
        if (cnt == n-1) break;
    }

    cout << answer << endl;
}

int main() {
   input();
}