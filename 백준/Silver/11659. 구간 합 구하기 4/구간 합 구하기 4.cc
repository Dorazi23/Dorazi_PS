#include <bits/stdc++.h>
using namespace std;

int n, m;
long long d[100005];
int num[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        d[i] = d[i-1] + num[i];
    }
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << '\n';
    }
}