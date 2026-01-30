#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 1e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<pair<int,int>> v;
vector<int> res;

bool cmp (pair<int,int> a, pair<int,int> b) {
    if (a.X == b.X) return a.Y > b.Y;
    return a.X < b.X;
}

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) { // i 번째 사람 왼쪽에는 
        int m; cin >> m; // 자기보다 큰 m 명이 존재한다
        v.push_back({m,i});
    }

    sort(v.begin(), v.end(), cmp);
    
    for (auto x : v) {
        int leftBig = x.X, num = x.Y;
        if (res.empty()) res.push_back(num);
        else {
            bool flag = false;
            int cnt = 0;
            for (auto cursor = res.begin(); cursor != res.end(); cursor++) {
                if (cnt == leftBig) {
                    res.insert(cursor, num);
                    flag = true;
                    break;
                }

                if (*cursor > num) cnt++;
            }

            if (!flag) res.push_back(num);
        }
    }

    for (auto x : res) cout << x << " ";
}

int main() {
    fastio;
    input();
}