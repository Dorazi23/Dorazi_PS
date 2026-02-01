#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int dp[105][105];
stack<char> st;
string a, b;

void input () {
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
        }
    }

    queue<pair<int,int>> q;
    q.push({a.size(), b.size()});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.X, y = cur.Y;
        if (x == 0 || y == 0) break;
        
        if (dp[x][y] == dp[x-1][y]) q.push({x-1, y});
        else if (dp[x][y] == dp[x][y-1]) q.push({x, y-1});
        else {
            st.push(a[x-1]);
            q.push({x-1, y-1});
        }
    }

    while (!st.empty()) {
        cout << st.top(); st.pop();
    }
}

int main() {
    fastio;
    input();
}