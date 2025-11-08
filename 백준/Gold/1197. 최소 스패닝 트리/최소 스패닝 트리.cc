#include <bits/stdc++.h>
using namespace std;
vector<int> p(10005, -1);
tuple<int,int,int> edge[100005];
int v, e; 

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e; 
    for (int i = 0; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
}

int find (int x) {
    if (p[x] < 0 ) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group (int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int cnt = 0; 
int ans = 0;

void answer(){
    sort(edge, edge + e);

    for (int i = 0; i < e; i++) {
        auto [c, a, b] = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += c; 
        cnt++;
        if(cnt == v-1) break;
    }
    
    cout << ans << endl;
}

int main() {
    input();
    answer();
}