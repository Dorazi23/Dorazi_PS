#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, a, b;
deque<int> dq;

void input () {
    cin >> n >> a >> b;
    if (a + b >= n + 2) {
        cout << "-1" << endl;
        return;
    }

    int tallest = max(a, b);
    for (int i = 1; i < a; i++) dq.push_back(i);
    dq.push_back(tallest);
    for (int i = b-1; i >= 1; i--) dq.push_back(i);
    
    int first = dq.front();
    dq.pop_front();
    while (dq.size() < n-1) dq.push_front(1);
    dq.push_front(first);

    for (auto val : dq) cout << val << " ";
}

int main() {
    fastio;
    input();
}