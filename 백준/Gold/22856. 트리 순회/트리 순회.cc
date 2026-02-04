#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e18
using namespace std;
using ll = long long;
int n, lc[100005], rc[100005]; 
vector<int> res;
stack<int> st;

void func (int cur) {
    if (cur == -1) return;
    func (lc[cur]);
    st.push(cur);
    func (rc[cur]);
}

void inOrder (int cur) {
    if (cur == -1) return;
    res.push_back(cur);
    if (lc[cur] != -1) {
        inOrder(lc[cur]);
        res.push_back(cur);
    }
    if (rc[cur] != -1) {
        inOrder(rc[cur]);
        res.push_back(cur);
    }
    if (cur == st.top()) { // 마지막 노드의 lc, rc 탐색 끝
        cout << res.size()-1 << endl;
        exit(0);
    }
}

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, l, r; cin >> u >> l >> r;
        lc[u] = l, rc[u] = r;
    }

    func (1);
    inOrder(1);
}

int main() {
    fastio;
    input();
}