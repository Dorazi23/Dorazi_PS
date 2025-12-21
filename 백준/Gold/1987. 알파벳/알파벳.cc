#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
string board[100];
deque<char> past;
int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, -1, 1};
bool vis[100][100];
bool used[26];

bool check (int x, int y) {
    int ch = board[x][y] - 'A';
    if (used[ch]) return true;
    else return false;
}

bool oob (int x, int y) {
    return x >= n || x < 0 || y >= m || y < 0;
}

void input() {
    fastio; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
}

int dist = 1, answer;
void ans(int x, int y) {
    answer = max (answer, dist);
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (oob(nx, ny) || check(nx, ny)) continue; // 맵 밖이거나 이미 지난 곳이면 안됨
        if (!vis[nx][ny]) {    
            int ch = board[nx][ny] - 'A';
            
            vis[nx][ny] = 1;
            dist++;
            used[ch] = 1;
            
            ans(nx, ny);
    
            used[ch] = 0;
            dist--;
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    input();

    vis[0][0] = 1;
    int ch = board[0][0] - 'A';
    used[ch] = 1;
    ans (0, 0);
    cout << answer << endl;
}