#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, k;
vector<pair<int,int>> jewel;
vector<int> bag;
priority_queue<int> pq;
ll answer;

void input () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, v; cin >> m >> v;
        jewel.push_back({m, v});
    }
    sort(jewel.begin(), jewel.end());
    
    while (k--) {
        int num; cin >> num;
        bag.push_back(num);
    }
    sort(bag.begin(), bag.end());

    int idx = 0;
    for (auto limit : bag) {
        while (idx < n && limit >= jewel[idx].X) {
            pq.push(jewel[idx].Y);
            idx++;
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}