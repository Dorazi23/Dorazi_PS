#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int n;
vector<int> V;
set<int> s;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        s.insert(m);
        V.push_back(m);
    }

    vector<int> v;
    for (auto x : s) v.push_back(x);
    for (int i = 0; i < n; i++) {
        int tar = V[i];
        int res = lower_bound(v.begin(), v.end(), tar) - v.begin();
        cout << res << " ";
    }
    
}

int main() {
    fastio;
    input();
}
