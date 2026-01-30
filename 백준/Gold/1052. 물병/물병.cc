#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k;

int func (int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += (x % 2);
        x /= 2;
    }
    return cnt;
}

void input () {
    cin >> n >> k;
    if (func(n) <= k) cout << "0" << endl;
    else {
        for (int i = n+1; i <= 20000005; i++) {
            if (func(i) <= k) {
                cout << i-n << endl;
                return;
            }
        }

        cout << -1 << endl;
    }
}

int main() {
    fastio;
    input();
}