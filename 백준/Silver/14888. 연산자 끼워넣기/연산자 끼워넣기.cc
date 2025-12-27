#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<int> nlist;
vector<int> operation;
int mx = INT_MIN, mn = INT_MAX;

int compute (int x, int y, int opt) {
    if (opt == 1) return x + y;
    else if (opt == 2) return x - y;
    else if (opt == 3) return x * y;
    else {
        return x / y;
    }
}

void input () {
    fastio; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nlist.push_back(num);
    }

    for (int i = 1; i <= 4; i++) { // + - x /
        
        int cnt; cin >> cnt;
        while(cnt--) {
            operation.push_back(i);
        }
    }
}

void ans() {

    do {
        int tot = nlist[0], idx = 1;
        for (auto opt : operation) {
            tot = compute (tot, nlist[idx], opt);
            idx++;
        }
        mx = max(mx, tot);
        mn = min(mn, tot);
    } while (next_permutation(operation.begin(), operation.end()));

    cout << mx << endl;
    cout << mn << endl;
}

int main() {
    input();
    ans();
}