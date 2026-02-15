#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n;
bool vis[105][105];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
double tot, p[5];

void input () {    
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> p[i];

    vis[50][50] = 1;
    auto ret = [&] (const auto& self, int x, int y, int cnt, double prob) -> void {
        if (cnt == n) {
            tot += prob;
            // cout << prob << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; 
            int ny = y + dy[dir];
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            double dprob = p[dir] / 100; // 방향에 따른 확률을 백분율로 전환
            self(self, nx, ny, cnt+1, prob * dprob);
            vis[nx][ny] = 0;
        }
    };
    ret(ret, 50, 50, 0, 1);
    
    cout << tot << endl;
}

int main() {
    fastio;
    cout.precision(20);
    input();
}