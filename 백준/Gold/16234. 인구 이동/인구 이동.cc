#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int n, L, R, board[105][105], board2[105][105];
bool vis[105][105]; 

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool oob (int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool makeUnion () {
    memset(board2, 0, sizeof(board2));
    memset(vis, 0, sizeof(vis));
    bool flag = false;
    queue<pair<int,int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            int total = board[i][j], count = 1;
            vector<pair<int,int>> v; 
            vis[i][j] = 1;
            q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (oob(nx, ny) || vis[nx][ny]) continue;

                    int diff = abs(board[x][y] - board[nx][ny]);
                    if (L <= diff && diff <= R) {
                        flag = true; 
                        vis[nx][ny] = 1;
                        total += board[nx][ny];
                        count++;
                        v.push_back({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }

            int res = total / count;
            board2[i][j] = res;
            if (!v.empty()) {
                for (auto [x, y] : v) board2[x][y] = res;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = board2[i][j];
        }
    }

    if (!flag) return false; // 어떤 국가도 국경을 열지 않음
    return true;
}


void input () {
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    while (true) {
        if (makeUnion()) answer++;
        else break;
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}