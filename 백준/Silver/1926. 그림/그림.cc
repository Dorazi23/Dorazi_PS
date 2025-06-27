#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

int board[502][502]={ 0, };
bool vis[502][502];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n, m;
int mx, num=0; //mx max, num 그림개수

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    //(i,j)부터 bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] != 1 || vis[i][j]) continue;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            num++;
            int area = 0;
            while(!Q.empty()){//해당 칸의 그림 넓이 구하기
                area++;
                pair<int,int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout<<num<<'\n'<<mx;
 
}