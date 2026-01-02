#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, add, p;
vector<int> nlist;
vector<pair<int,int>> order;

void input() {
    fastio; cin >> n >> add >> p;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nlist.push_back(num);
    }

    if (n == p && nlist.back() >= add) {
        cout << "-1" << endl;
        return;
    }

    nlist.push_back(add);
    sort(nlist.begin(), nlist.end(), greater<>());

    
    order.push_back({nlist[0], 1});
    int idx = 1;
    int stack = 0;
    for (int i = 1; i < nlist.size(); i++) {
        int cur = nlist[i];
        int prev = nlist[i-1];

        if (cur == prev) { // 이전과 등수가 동일할 때 
            order.push_back({cur, idx});
            stack++;
        }
        else { // 이전과 등수가 동일하지 않을 때
            if (stack == 0) {
                idx++;
                order.push_back({cur, idx});
            }
            else {
                idx += (stack+1);
                order.push_back({cur, idx});
                stack = 0;
            }
        }
    }

    for (auto val : order) {
        if (val.X == add) {
            if (val.Y <= p) cout << val.Y << endl;
            else cout << "-1" << endl;
            break;
        }
    }
}

int main() {
    input();
}