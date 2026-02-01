#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<int> v, temp;
bool vis[100];
int n, m;

void func (int cnt) {
    if (cnt == m) {
        for (auto x : v) cout << x << " ";
        cout << endl;

        return;
    }

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        func(cnt+1);
        v.pop_back();
    }
}

void input () {
    cin >> n >> m;
    func (0);
}

int main() {
    fastio;
    input();
}