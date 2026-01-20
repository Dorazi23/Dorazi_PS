#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, answer;
vector<int> p(1000005, -1);
vector<bool> vis(1000005);
string board[1005];

int Find (int x) {
    if (p[x] < 0) return x;
    return p[x] = Find(p[x]);
}

bool Union (int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i, y = j;
            if (board[i][j] == 'U') x--;
            else if (board[i][j] == 'D') x++;
            else if (board[i][j] == 'L') y--;
            else y++;
            Union(m*i+j, m*x+y);
        }
    }

    for (int i = 0; i < n*m; i++) {
        if (p[i] < 0) answer++;
    }
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}