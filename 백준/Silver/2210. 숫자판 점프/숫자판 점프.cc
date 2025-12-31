#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char arr[15][15];
bool vis[15][15];
unordered_set<string> cnt;

bool oob (int x, int y) {
    return x >= 5 || x < 0 || y >= 5 || y < 0;
}

void func(string s, int x, int y) {
    if (s.size() >= 6) {
        cnt.insert(s);
        return;
    } 
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (oob(nx,ny)) continue;
        s.push_back(arr[nx][ny]);
        
        func(s, nx, ny);
        s.pop_back();
    }
}

void input() {
    fastio;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            func (string(1, arr[i][j]), i, j);
        }
    }

    // for (auto val : cnt) {
    //     cout << val << endl;
    // }
    cout << cnt.size() << endl;
}

int main() {
    input();
}