#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, arr[25][25], mn = MAX;
bool vis[25];

void func (vector<int>& a, int start) {
    if (a.size() == n/2) { // 값 계산
        int res1 = 0;
        for (auto i : a) {
            for (auto j : a) {
                res1 += arr[i][j];
            }
        }

        int res2 = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!vis[i] && !vis[j]) {
                    res2 += arr[i][j];
                }
            }
        }

        mn = min(mn, abs(res1 - res2));
    }

    for (int i = start; i <= n; i++) {
        a.push_back(i);
        vis[i] = 1;
        func(a, i+1);
        vis[i] = 0;
        a.pop_back();
    }
}

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> v;
    func(v, 1);

    cout << mn << endl;
}

int main() {
    fastio;
    input();
}