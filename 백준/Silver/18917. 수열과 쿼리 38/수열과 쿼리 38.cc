#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 0x4f4f4f4f
using namespace std;
using ll = long long;
int n;
unordered_map<int,int> um;
ll total, res;

void input () {
    um.insert({0, 1});
    
    cin >> n;
    while (n--) {
        int cmd, x; cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (um.find(x) != um.end()) um[x]++;
            else um.insert({x, 1});
            total += x;
            res ^= x;
        }
        else if (cmd == 2) {
            cin >> x;
            total -= x;
            um[x]--;
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