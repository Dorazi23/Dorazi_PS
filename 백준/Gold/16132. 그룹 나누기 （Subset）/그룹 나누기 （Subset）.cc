#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n, N;
ll dp[1500]; // dp[k] = 합이 k가 되는 경우의 수

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) N += i;

    if (N & 1) {
        cout << "0" << endl;
        return;
    }

    // 숫자 i를 사용해서 합 j를 만드는 경우의 수는 
    // 합 j−i를 만드는 모든 경우에 i를 하나씩 붙인 것이다.
    N /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) { 
        for (int j = N; j >= i; j--) {
            dp[j] += dp[j-i];
        }
    }

    cout << dp[N] / 2;
}

int main() {
    fastio;
    input();
}