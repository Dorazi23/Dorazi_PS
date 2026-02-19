#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, k;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char board[1005][1005];
int dist[1005][1005][12][2];
bool OutOfBound(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs(){
    memset(dist, -1, sizeof(dist));
    dist[0][0][0][0] = 1;
    queue<tuple<int, int, int, int>> q;
    q.push({0,0,0,0}); 
    while(!q.empty()){
        auto [x, y, z, t] = q.front(); q.pop();
        if(x == n-1 && y == m-1) return  dist[x][y][z][t];
        int nextdist = dist[x][y][z][t] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OutOfBound(nx, ny)) continue;
            if(t == 0){ //낮일 때
                if(board[nx][ny] == '0' && dist[nx][ny][z][1] == -1){ //벽이 아닌 곳에 처음갈 때
                    dist[nx][ny][z][1] = nextdist;
                    q.push({nx,ny,z,1});
                }
                if(board[nx][ny] == '1' && z < k && dist[nx][ny][z+1][1] == -1){ //벽인 곳에 처음갈 때
                    dist[nx][ny][z+1][1] = nextdist;
                    q.push({nx,ny,z+1,1});
                }
            }
            else{ //밤일 때 
                if(board[nx][ny] == '0' && dist[nx][ny][z][0] == -1){ //벽이 아닌 곳에 처음갈 때
                    dist[nx][ny][z][0] = nextdist;
                    q.push({nx,ny,z,0});
                }
                if(board[nx][ny] == '1' && z < k && dist[nx][ny][z+1][1] == -1){ //정지
                    dist[x][y][z][0] = nextdist;
                    q.push({x, y, z, 0});
                }
            }
        }
    }
    return -1;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs() << endl;
}