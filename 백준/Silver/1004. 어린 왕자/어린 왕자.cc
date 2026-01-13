#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int x, y, u, v, n;

void input () {
    int answer = 0;
    cin >> x >> y >> u >> v;
    cin >> n;
    while (n--) {
        int cx, cy, r; cin >> cx >> cy >> r;

        int ds = (cx-x)*(cx-x) + (cy-y)*(cy-y);
        int de = (cx-u)*(cx-u) + (cy-v)*(cy-v);

        r = r*r;

        // 두 좌표 모두 원에 포함될 때, 
        if ((r > ds && r > de) || (r < ds && r < de)) continue;
        else answer++;
    }

    cout << answer << endl;
}

int main() {
    fastio; 
    int t; cin >> t;
    while (t--) {
        input(); 
    }
}