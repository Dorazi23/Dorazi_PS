#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> p(100005, -1);
tuple<int,int,int> edge[1000005]; // cost, a, b

int n, m;
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    if (n == 2) {
        cout << "0" << endl;
        exit(0);
    } 
    for (int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
}

int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni (int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    if (p[v] < p[u]) swap(u,v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

void ans() {
    sort(edge, edge+m);
    int count = 1;
    int sum = 0;

    for (int i = 0; i < m; i++) {
        auto [cost, a, b] = edge[i];
        if (find(a) == find(b)) continue;
        uni(a,b);
        sum += cost;
        count++;
        if (count == n-1) break;
    }
    
    cout << sum << endl;
}

int main() {
    input();
    ans();
}