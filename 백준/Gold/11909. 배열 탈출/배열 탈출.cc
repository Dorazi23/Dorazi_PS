#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
int arr[2300][2300];
int dp[2300][2300];
int dx[] = {0, 1};
int dy[] = {1, 0};

bool oob (int x, int y) {
    return x <= 0 || x > n || y <= 0 || y > n;
}

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
}

void ans () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = MAX;
        }
    }

    queue<pair<int,int>> q;
    q.push({1, 1});
    dp[1][1] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int tar = arr[cur.X][cur.Y];
        int res = MAX;
        for (int dir = 0; dir < 2; dir++) { // tar -> val 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (oob(nx, ny)) continue;

            int val = arr[nx][ny];
            if (tar > val) { // 다음 단계로 넘어가는데 문제 없는 경우
                res = dp[cur.X][cur.Y];
            }
            else { // 다음 단계로 넘어가는데 문제 있는 경우 
                res = dp[cur.X][cur.Y] + arr[nx][ny] - arr[cur.X][cur.Y] + 1;
            }

            if (dp[nx][ny] == MAX) {
                dp[nx][ny] = res;
                q.push({nx, ny});
            }
            else {
                if (dp[nx][ny] <= res) continue;
                dp[nx][ny] = res;
                q.push({nx, ny});
            }
        }
    }

    cout << dp[n][n] << endl;
}

int main() {
    input();
    ans();
}