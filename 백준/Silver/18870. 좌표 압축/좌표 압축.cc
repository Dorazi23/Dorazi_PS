#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define X first
#define Y second
using namespace std;
int n, arr[1000005];
map<int,int> m;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) m.emplace(arr[i], 0);

    int cnt = 0;
    for (auto& [num, idx] : m) idx = cnt++;

    for (int i = 0; i <n; i++) {
        cout << m.find(arr[i])->Y << " ";
    }
}

int main() {
    fastio;
    input();
}