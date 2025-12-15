#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<int> order;

void input() {
    fastio; cin >> n;
    while(n--) {
        int num; cin >> num;
        order.push_back(num);
    }
    sort(order.begin(), order.end()); 
    
}

ll answer;
void ans() {
    int idx = 1;
    for (auto val : order) {
        answer += abs(idx-val);
        idx++;
    }
    cout << answer << endl;
}


int main() {
    input();
    ans();
}