#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, cnt;
int kdx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int kdy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};
bool vis[5][10005];
bool flag = false;
pair<int,int> path[20005];
int pathLen;

bool oob (int x, int y) {
    return x <= 0 || x > 2 || y <= 0 || y > n;
}

void move (int x, int y, int cnt) {
    if (cnt == 2*n) {
        cout << "YES" << endl;
        for (int i = 0; i < pathLen; i++) {
            cout << path[i].X << " " << path[i].Y << endl;
        }
        flag = true;
        return;
    }
    
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + kdx[dir];
        int ny = y + kdy[dir];
        if (oob(nx,ny) || vis[nx][ny]) continue;
        if (flag) break;
        vis[nx][ny] = 1;
        path[pathLen++] = {nx, ny};
        move(nx, ny, cnt+1);
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx,ny) || vis[nx][ny]) continue;
        if (flag) break;
        vis[nx][ny] = 1;
        path[pathLen++] = {nx, ny};
        move(nx, ny, cnt+1);
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            pathLen = 0;
            memset(vis, 0, sizeof(vis));
            cnt = 0;
            vis[i][j] = 1;
            path[pathLen++] = {i, j};
            move(i, j, 1);
            if (flag) return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    fastio;
    input();
}