#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
vector<ll> len;
vector<ll> price;
ll last;
ll answer;
ll mn = 0x7f7f7f7f;

void input() {
    fastio; cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll num; cin >> num;
        len.push_back(num);
        last += num;
    }
    
    
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        price.push_back(num);
        if (i != n-1) mn = min(mn, num);
    }
}

ll past;
void ans() {
    for (int i = 0; i < n; i++) {
        if (price[i] == mn) {
            answer += mn * last;
            cout << answer << endl;
            return;
        }
        else answer += (price[i] * len[i]);
        last = last - len[i];
        
    }
}

int main() {
    input();
    ans();
}