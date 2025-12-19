#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, tar, tar_score;
vector<pair<int,int>> v;

bool cmp (pair<int,int> a, pair<int,int> b) {
    if (a.Y > b.Y) return a > b;
    else return a < b;
}

void input() {
    fastio;
    cin >> n >> tar;
    for (int i = 1; i <= n; i++) {
        int order; cin >> order;
        int a, b, c; cin >> a >> b >> c;
        
        int tot = 3*a + 2*b + c;
        if (order == tar) tar_score = tot; // 타겟과 순서가 동일하면, 그 점수를 저장
        v.push_back({order, tot});
        
    }

    sort(v.begin(), v.end(), cmp);

    int answer = 1;
    for (int i = 0; i < n; i++) {
        auto cmp = v[i];
        if (cmp.Y > tar_score) answer++;
        if (cmp.Y == tar_score) {
            cout << answer << endl;
            return;
        }
    }
}
 
int main() {
    input();
}