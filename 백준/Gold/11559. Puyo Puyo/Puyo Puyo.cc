#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int res;
string board[15], temp[15];
bool vis[15][15];
deque<pair<int,int>> dq;

bool oob (int x, int y) {
    return x < 0 || x >= 12 || y < 0 || y >= 6;
}

void move () {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            temp[i][j] = board[i][j];
        }
    }
    
    for (auto [x, y] : dq) temp[x][y] = '.';

    for (int j = 0; j < 6; j++) {
        deque<char> block;
        for (int i = 11; i >= 0; i--) {
            if (temp[i][j] == '.') continue;
            block.push_back(temp[i][j]);
            temp[i][j] = '.';
        }

        int idx = 11;
        for (auto ch : block) {
            temp[idx][j] = ch;
            idx--;
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

bool bfs (int i, int j) {
    char ch = board[i][j];
    vector<pair<int,int>> tmp;
    
    queue<pair<int,int>> q;
    vis[i][j] = 1;
    tmp.push_back({i, j});
    q.push({i, j}); 
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 맵 밖이거나 같은 색의 뿌요가 아니거나, 이미 방문했으면 넘김
            if (oob(nx, ny) || board[nx][ny] != ch || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            tmp.push_back({nx, ny});
            q.push({nx, ny});
        }
    }

    if (tmp.size() >= 4) {
        for (auto [x, y] : tmp) dq.push_back({x, y});
        return 1;
    }
    else return 0;
}

void input () {
    for (int i = 0; i < 12; i++) cin >> board[i];

    while (true) {
        memset(vis, 0, sizeof(vis));
        dq.clear();
        bool flag = false;
        
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.' || vis[i][j]) continue;
                if (bfs(i, j)) flag = true;
            }
        }

        if (!flag) break;
        
        move();
        res++;
    }

    cout << res << endl;
}

int main() {
    fastio;
    input();
}

/*
연쇄 = 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 한꺼번에 없어짐 
뿌요들이 없어지고 나서 위에 다른 뿌요가 있다면 중력의 영향을 받아 아래로 떨어
연쇄 시 가능한 많은 뿌요들이 터짐
*/