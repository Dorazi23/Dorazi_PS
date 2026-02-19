#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n;
ll total, res;

void input () {    
    cin >> n;
    while (n--) {
        int cmd, x; cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            total += x;
            res ^= x;
        }
        else if (cmd == 2) {
            cin >> x;
            total -= x;
            res ^= x;
        }
        else if (cmd == 3) cout << total << endl;
        else cout << res << endl;
    }
}

int main() {
    fastio;
    input();
}