#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n, k;
ll dp[205][205];

void input () {
    for (int i = 0; i <= 204; i++) fill(dp[i], dp[i]+204, -1);
    
    cin >> n >> k;
    for (int i = 0; i <= n; i++) dp[i][1] = 1;

    auto func = [&] (const auto& self, int cur, int cnt) -> ll {
        if (cnt == 0) return 0;
        
        ll& ret = dp[cur][cnt];
        if (ret != -1) return ret % MAX;
        
        ret = 0;
        for (int i = 0; i <= cur; i++) {
            ret = (ret + self(self, i, cnt-1) % MAX) % MAX;
        }
        
        return ret;
    };

    cout << func(func, n, k);
}

int main() {
    fastio;
    input();
}