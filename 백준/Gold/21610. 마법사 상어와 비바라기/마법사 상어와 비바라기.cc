#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int n, m, board[105][105];
int s, dir;
bool chk[105][105];
queue<pair<int,int>> q; 
queue<pair<int,int>> q2;

bool oob (int x, int y) { // 물의 양이 증가할 때, 맵 밖은 제외하기 위함 
    return x <= 0 || x > n || y <= 0 || y > n;
}

void move (int dir, int s) {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int nx = x + (s % n) * dx[dir];
        int ny = y + (s % n) * dy[dir];
        // 무한 보드 처리 
        if (nx > n) nx -= n;
        if (nx <= 0) nx += n;
        if (ny > n) ny -= n;
        if (ny <= 0) ny += n;
        board[nx][ny]++;
        chk[nx][ny] = 1;
        q2.push({nx, ny});
    }
}

void makeCloud () {
    while (!q2.empty()) {
        auto [x, y] = q2.front(); q2.pop();
        for (int dir = 1; dir <= 4; dir++) { // 2*dir = 대각선 
            int nx = x + dx[2*dir];
            int ny = y + dy[2*dir];
            if (oob(nx, ny)) continue;
            if (board[nx][ny] >= 1) { // 대각선에 물이 있으면 증가 
                board[x][y]++;
            }
        }
    }

    // q에 들어있던 좌표는 구름이 발생하면 안됨 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 이전에 구름이 소멸된 적 없고, 물의 양이 2 이상일 때 
            if (!chk[i][j] && board[i][j] >= 2) {
                board[i][j] -= 2;
                q.push({i, j});
            }
        }
    }

    memset(chk, 0, sizeof(chk));
}

void input () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    q.push({n, 1});
    q.push({n, 2});
    q.push({n-1, 1});
    q.push({n-1, 2});
    while (m--) {
        cin >> dir >> s;
        move(dir, s);
        makeCloud();
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            answer += board[i][j];
        }
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}