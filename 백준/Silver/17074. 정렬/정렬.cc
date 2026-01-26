#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n;
int v[100005];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 0;
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            if (l == 0 && r == 0) l = i, r = i+1;
            else {
                cout << "0";
                return;
            }
        }
    }

    int answer = 0;
    if (l == 0 && r == 0) cout << n << endl;
    else { 
        // l을 없애는 경우 
        if (l == 0) answer++;
        else {
            if (v[l-1] <= v[r]) answer++;
        }
        
        // r을 없애는 경우 
        if (r == n-1) answer++;
        else {
            if (v[l] <= v[r+1]) answer++;
        }

        cout << answer << endl;
    }
}

int main() {
    fastio;
    input();
}