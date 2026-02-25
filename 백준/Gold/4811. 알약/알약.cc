#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n;
ll dp[35][105];

void input () {

    memset(dp, -1, sizeof(dp));
    // func(w, h) = 큰 알약 w개, 작은 알약 h개 남았을 때 먹을 수 있는 가짓 수
    auto func = [&] (const auto& self, int w, int h) -> ll {
        if (w == 0 && h == 0) return 1;
        ll& ret = dp[w][h];
        if (ret != -1) return ret;

        ret = 0;

        // 쪼개진 알약이 하나라도 있으면
        if (h >= 1) {
            // 더 쪼갤 수 있을 때
            if (w >= 1) ret += self(self, w-1, h+1) + self(self, w, h-1);
            // 없을 때
            else ret += self(self, w, h-1);
        }
        else ret += self(self, w-1, h+1);

        return ret;
    };

    while (cin >> n) {
        if (n == 0) return;
        else cout << func(func, n, 0) << endl;
    }
}

int main() {
    fastio;
    input();
}