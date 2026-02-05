#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e18
using namespace std;
using ll = long long;
int n, m;
vector<bool> isCycle(505);
vector<int> p(505, -1);

int Find (int x) {
    if (p[x] < 0) return x;
    return p[x] = Find(p[x]);
}

bool Union (int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) {
        isCycle[u] = isCycle[v] = 1;
        return false;
    }
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;

    if (isCycle[u] || isCycle[v]) { // 합치려는 큰 그래프가 사이클이 존재 
        // 사이클 x인 노드들도 사이클로 취급
        isCycle[u] = isCycle[v] = 1;
    }
    return true;
}

void input () {
    int loopNum = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        int cnt = 0;
        fill (p.begin(), p.end(), -1);
        fill (isCycle.begin(), isCycle.end(), 0);
        loopNum++;
        
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            Union(u, v);
        }

        // 사이클이 없는 루트 노드의 개수 세
        for (int i = 1; i <= n; i++) {
            // cout << i << ": " << p[i] << " " << isCycle[i] << endl;
            if (p[i] < 0 && !isCycle[i]) cnt++;
        }
  
        cout << "Case " << loopNum << ": ";
        if (cnt > 1) cout << "A forest of " << cnt << " trees." << endl;
        else if (cnt == 1) cout << "There is one tree." << endl;
        else cout << "No trees." << endl;
    }
}

int main() {
    fastio;
    input();
}