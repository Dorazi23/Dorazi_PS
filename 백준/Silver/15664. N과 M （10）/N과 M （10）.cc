#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
bool vis[15];
vector<int> arr, v;

void func (int start, int cnt) {
    if (cnt == m) {
        for (auto x : v) cout << x << " ";
        cout << endl;
        return;
    }

    int pre = 0;
    for (int i = start; i < n; i++) {
        if (vis[i] || pre == arr[i]) continue;
        pre = arr[i];
        v.push_back(arr[i]);
        vis[i] = 1;
        func (i, cnt+1);
        vis[i] = 0;
        v.pop_back();
    }
}

void input () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    func (0, 0);
}

int main() {
    fastio;
    input();
}