#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000005
#define INF 4e18
using namespace std;
using ll = long long;
int n, cnt, answer;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool board[30];

bool oob (int x, int y) {
    return x < 0 || x > 24 || y < 0 || y > 24;
}

bool chk[30][30], vis[30][30];
bool connect (vector<int>& v) {
    memset(chk, 0, sizeof(chk));
    memset(vis, 0, sizeof(vis));
    for (auto x : v) chk[x/5][x%5] = 1;
    queue<pair<int,int>> q;
    
    vis[v[0]/5][v[0]%5] = 1;
    q.push({v[0]/5, v[0]%5});
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (oob(nx,ny)) continue;
            if (!chk[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    // 체크한 곳이 방문한 적 없으면 이어져있지 않음 
    for (auto x : v) {
        if(!vis[x/5][x%5]) return false;
    }

    return true;
}

bool check (vector<int>& v) { // 다솜파가 4명 이상인지 확인 
    int cnt = 0;
    for (auto x : v) {
        if (board[x]) cnt++;
    }
    if (cnt >= 4) return true;
    else return false;
}

void input () {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char ch; cin >> ch;
            if (ch == 'S') {
                board[(5*i)+j] = 1;
                cnt++;
            }
            else board[(5*i)+j] = 0;
        }
    }

    if (cnt < 4) {
        cout << 0 << endl;
        return;
    }
    
    vector<int> v, temp;
    for (int i = 0; i < 25; i++) v.push_back(i);
    for (int i = 1; i <= 25; i++) {
        if (i <= 7) temp.push_back(1);
        else temp.push_back(0);
    }
    
    do {
        vector<int> res;
        for (int i = 0; i < 25; i++) {
            if (temp[i]) res.push_back(v[i]);
        }
        if (check(res) && connect(res)) answer++;
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}