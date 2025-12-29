#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int dice[10]; 
int board[100][100];
vector<int> cmd;
vector<pair<int,int>> dir = { // x, 동, 서, 북, 남
{}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};
int n, m, sx, sy, k;
int up, down, east, west, south, north;

//   3
// 1   2
//   4

bool oob (int x, int y) {
    return x >= n || x < 0 || y >= m || y < 0;
}

int mapping_num (int x) {
    if (x == 1) return 6;
    else if (x == 2) return 5;
    else if (x == 3) return 4;
    else if (x == 4) return 3;
    else if (x == 5) return 2;
    else return 1;
}

void roll_dice(int x, int y, int d) { // (x,y)에서 d 방향으로 구른다
    int p_up = up;
    int p_down = down;
    int p_east = east;
    int p_west = west;
    int p_south = south;
    int p_north = north;
    
    if (d == 1) { // 동 -> 남/북 안 변함
        // 위치 갱신
        up = mapping_num(p_east);
        down = p_east;
        east = p_up;
        west = mapping_num(p_up);
    }
    else if (d == 2) { // 서 -> 남/북 안 변함
        // 위치 갱신
        up = mapping_num(p_west);
        down = p_west;
        east = p_down;
        west = mapping_num(p_down);
    }
    else if (d == 3) { // 북 -> 동/서 안 변함
        // 위치 갱신
        up = mapping_num(p_north);
        down = p_north; 
        south = p_down;
        north = mapping_num(p_down);
    }
    else { // 남 -> 동/서 안 변함
        // 위치 갱신
        up = mapping_num(p_south);
        down = p_south;
        south = p_up;
        north = mapping_num(p_up);
    }

    // 맵과 주사위 값 갱신 
    if (board[x][y] == 0)
        board[x][y] = dice[down];
    else {
        dice[down] = board[x][y];
        board[x][y] = 0;
    }
}

void input() {
    fastio; cin >> n >> m >> sx >> sy >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while(k--) {
        int num; cin >> num;
        cmd.push_back(num);
    }
}

void ans() {
    pair cur = {sx, sy};
    up = 1; 
    down = mapping_num(1);
    east = 3;
    west = mapping_num(3);
    south = mapping_num(2);
    north = 2;
    
    for (auto val : cmd) {
        int nx = cur.X + dir[val].X;
        int ny = cur.Y + dir[val].Y;

        if (oob(nx,ny)) continue; // 맵 밖을 나가면 스킵 

        roll_dice (nx, ny, val);
            
        cout << dice[up] << endl;
        cur = {nx, ny}; // 새로운 좌표 갱신 
    }
    
}

int main() {
    input();
    ans();
}