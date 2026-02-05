#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e18
using namespace std;
using ll = long long;
int n, d;
vector<pair<int,int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
string s;
bool vis[1005][1005];
int mnR = 50, mxR = 50, mnC = 50, mxC = 50;

void turn (char c) {
    if (c == 'R') {
        if (d == 3) d = 0;
        else d++;
    }
    else {
        if (d == 0) d = 3;
        else d--;
    }
}

void input () {
    cin >> n >> s;
    int x = 50, y = 50;
    vis[x][y] = 1;
    for (auto ch : s) {
        if (ch == 'F') {
            x = x + dir[d].X;
            y = y + dir[d].Y;
            vis[x][y] = 1;
        }
        else {
            turn(ch);
        }
        mnR = min(mnR, x); mxR = max(mxR, x);
        mnC = min(mnC, y); mxC = max(mxC, y);
    }

    for (int i = mnR; i <= mxR; i++) {
        for (int j = mnC; j <= mxC; j++) {
            if (vis[i][j]) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
}

int main() {
    fastio;
    input();
}