#include <bits/stdc++.h>
using namespace std;
vector<int> p(500005, -1);
int n, m;

int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni (int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(!uni(u,v)) { // 사이클이 존재하면 false 도출
            cout << i << endl;
            return;
        }
    }
    
    cout << "0" << endl;
}

int main() {
    input();

}