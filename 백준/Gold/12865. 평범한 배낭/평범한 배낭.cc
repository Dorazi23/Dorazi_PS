#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, k;
int w[105];
int v[105];
int d[105][100005]; // i번째 물건까지 확인하고 무게 j일 때 최대 가치 

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if(j < w[i]) d[i][j] = d[i-1][j];
            else d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
        }
    }
    cout << d[n][k];
}