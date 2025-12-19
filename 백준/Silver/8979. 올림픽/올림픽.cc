#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, tar;

vector<tuple<int,int,int>> v;
tuple<int,int,int> target;



void input() {
    fastio;
    cin >> n >> tar;
    for (int i = 1; i <= n; i++) {
        int order; cin >> order;
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a,b,c});
        if (order == tar) target = {a,b,c};
    }

    sort(v.begin(), v.end(), greater<>());

    int answer = 1;
    for (auto val : v) {
        auto [a,b,c] = val;
        if (val != target) answer++;
        else {
            cout << answer << endl;
            return;
        }
    }
}
 
int main() {
    input();
}