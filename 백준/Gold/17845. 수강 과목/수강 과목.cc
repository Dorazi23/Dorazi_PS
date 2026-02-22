#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, k, value[1005], need[1005];
ll dp[10005];

void input () {
    cin >> k >> n; // n 은 과목 수 
    for (int i = 0; i < n; i++) cin >> value[i] >> need[i];

    for (int i = 0; i < n; i++) {

        // dp[i] = 공부 시간이 j 일 때, 최대 중요도 
        for (int j = k; j >= 0; j--) { // 공부 시간 
            if (j - need[i] >= 0) dp[j] = max(dp[j], dp[j-need[i]] + value[i]);
        }
    }

    ll answer = 0;
    for (int i = 0; i <= k; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}