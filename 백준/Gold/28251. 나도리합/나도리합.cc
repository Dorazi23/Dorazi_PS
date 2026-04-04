#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, q;
ll arr[200005], sz[200005], power[200005];
vector<int> p(200005, -1); 

int Find (int x) {
    if (p[x] < 0) return x;
    return p[x] = Find(p[x]);
}

bool Union (int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    power[u] += power[v] + sz[u] * sz[v];
    sz[u] += sz[v];

    p[v] = u;
    return true;
}

void input () {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sz[i] = arr[i];
    }

    while (q--) { 
        int a, b; cin >> a >> b;
        Union(a, b);
        cout << power[Find(a)] << endl;
    }

    // 캄포넌트 확인용
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto x : component[i]) cout << x << " ";
    //     cout << endl;
    // }
}

int main() {
    fastio;
    input();
}