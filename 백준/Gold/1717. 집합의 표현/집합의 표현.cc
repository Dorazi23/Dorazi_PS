#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;
vector<int> p(1000005, -1);
int n, m;

int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni (int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) {
        swap(u, v);
    }
    if (p[u] == p[v]) {
        p[u]--;
    }
    p[v] = u;
    return true;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    // 0 a b -> a, b가 속해있는 그룹 각각을 서로 합침
    // 1 a b -> a, b가 같은 그룹에 속해있는지 확인 
    while(m--){
        int cal, a, b; cin >> cal >> a >> b;
        if (cal == 0 && a != b) {
            uni(a, b);
        }
        if (cal == 1) {
            if(find(a) == find(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {
    input();
}