#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000000
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;
ll d[105][15];
int n;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i < 10; i++) {
        d[1][i] = 1;
    }
    d[1][0] = 0;
    for (int i = 2; i <= n; i++) { //자릿수
        for (int j = 0; j < 10; j++) { //끝나는 수
            if(j == 0) d[i][0] = d[i-1][1] % MAX;
            else if(j == 9) d[i][9] = d[i-1][8] % MAX;
            else d[i][j] = (d[i-1][j-1] + d[i-1][j+1])  % MAX;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) { //자릿수
        ans = (ans + d[n][i]) % MAX;
    }
    cout << ans % MAX << endl;
}