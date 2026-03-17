#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define INF 0x4f4f4f4f
using namespace std;
int x, dp[1000005];

void input () {
    cin >> x;

    // func(cur): cur을 1로 만드는 데 필요한 횟수 
    fill (dp, dp+1000005, INF);
    auto func = [&] (const auto& self, int cur) -> int {
        if (cur == 1) return 0;

        int& ret = dp[cur];
        if (ret != INF) return ret;

        if (cur % 3 == 0) ret = min(ret, self(self, cur/3) + 1);
        if (cur % 2 == 0) ret = min(ret, self(self, cur/2) + 1);
        ret = min(ret, self(self, cur-1) + 1);
            
        return ret;
    };

    cout << func(func, x) << endl;
}

int main() {
    fastio;
    input();
}