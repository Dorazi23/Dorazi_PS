#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<int> adj[10005];
int Time[10005], deg[10005], dp[10005];
int n, tmp, answer;

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Time[i];
        int num; cin >> num;
        deg[i] = num;
        while (num--) {
            int m; cin >> m;
            adj[m].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            dp[i] = Time[i];
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + Time[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }

    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}