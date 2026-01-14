#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<pair<int,int>> v;
int n, answer, st = -1000000001, en = -1000000001;

void input () {
    cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        auto [x, y] = v[i];
        if (en < x) {
            answer += (en - st);
            st = x;
            en = y;
        }
        if (en < y) {
            en = y;
        }
    }

    answer += (en - st);
    cout << answer << endl;
}

int main() {
    fastio; 
    input();
}