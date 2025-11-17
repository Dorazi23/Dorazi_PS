#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x7fffffff
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<pair<int,int>> card;
bool check[1000005];
int score[1000005];
int mx = -1000; // 주어진 카드 번호 중 가장 큰 값

bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.Y < b.Y;
}

void input () {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        card.push_back({m, i}); // 카드 번호, 플레이어 번호
        check[m] = 1;
        mx = max(mx, m);
    }
}

void output () {
    for (int i = 0; i < n; i++) {
        int st = card[i].X * 2;
        while (st <= mx) {
            if (check[st]) {
                score[st] -= 1;
                score[card[i].X] += 1;
            }
            st += card[i].X;
        }
    }
    
    for (auto cur : card) {
        cout << score[cur.X] << " ";
    }
}
 
int main() {
    input();
    output();
}