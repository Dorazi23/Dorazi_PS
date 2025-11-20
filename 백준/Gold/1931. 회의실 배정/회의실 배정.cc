#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
vector<pair<int,int>> v;
int n;
int tmp[100005];

void input() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }
}

int answer = 1;
void ans() {
    sort(v.begin(), v.end());
    int last = v[0].X;
    for (int i = 1; i < n; i++) {
        if (v[i].Y >= last) {
            answer++;
            last = v[i].X;
        }
    }
    cout << answer << endl;
}

int main() {
    input();
    ans();
}