#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
vector<int> v;

void input () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) v.push_back(i);

    do {
        for (int i = 0; i < m; i++) cout << v[i] << " ";
        cout << endl;
        reverse(v.begin()+m, v.end());
    } while (next_permutation (v.begin(), v.end()));
}

int main() {
    fastio;
    input();
}