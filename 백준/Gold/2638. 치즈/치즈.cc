#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[105][105];
vector<pair<int,int>> cheese;
int n, m; 

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
}

bool OutOfBounds(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

void outAir(){
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OutOfBounds(nx,ny)) continue;
            if(board[nx][ny] != 0) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}

void melt(){
    cheese.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] != 1) continue;
            int count = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(OutOfBounds(nx,ny)) continue;
                if(vis[nx][ny]) count++;
            }
            if(count >= 2) cheese.push_back({i, j});
        }
    }

    for (int i = 0; i < cheese.size(); i++) {
        int x = cheese[i].X;
        int y = cheese[i].Y;
        board[x][y] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] == 1) return true;
        }
    }
    return false;
}

void solve(){
    
}

int main() {
    int time_cnt = 0;
    input();
    while(check()){
        outAir();
        melt();
        time_cnt++;
    }
    cout << time_cnt << endl;
}