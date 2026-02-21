#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
ll n, m, memory[105], cost[105];
ll total, dp[10005]; // dp[i] = 비용이 i 일 때, 메모리의 최댓값  

void input () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> memory[i];
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        total += cost[i];
    }
     
    // 앱은 유일하므로 중복되어선 안됨
    for (int i = 0; i < n; i++) {
        for (int j = total; j >= 0; j--) { // 중복 없이 골라야하므로 큰 수부터 
            if (j-cost[i] >= 0) dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
        }
    }

    int mn = INF; 
    // m 바이트 이상을 골라야 함
    for (int i = 0; i <= total; i++) {
        if (dp[i] >= m) mn = min(mn, i); 
    }

    cout << mn << endl;
}

int main() {
    fastio;
    input();
}