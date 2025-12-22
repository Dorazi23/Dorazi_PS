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
vector<int> v;

void input() {
    fastio;
    cin >> n;
    while(n--) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<>());

    for (auto val : v) {
        cout << val << endl;
    }
    
}

int main() {
    input();
}