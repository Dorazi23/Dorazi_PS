#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
ll answer;

void input () {
    cin >> n;
    int st = 1, en = 1, tot = 1;
    while (en <= n) {
        if (tot < n) {
            en++;
            tot += en;
        }
        else if (tot > n) {
            tot -= st;
            st++;
        }
        else {
            answer++;
            tot -= st;
            st++;
        }
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}