#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, arr[25][25];

void input () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> team, tmp;
    for (int i = 1; i <= n; i++) team.push_back(i);
    for (int i = 1; i <= n; i++) {
        if (i <= n/2) tmp.push_back(1);
        else tmp.push_back(0);
    }
    
    int mn = MAX;
    do {
        vector<int> res1, res2;
        for (int i = 0; i < n; i++) {
            if (tmp[i]) res1.push_back(team[i]);
            else res2.push_back(team[i]);
        }

        int score1 = 0;
        for (auto i : res1) {
            for (auto j : res1) {
                score1 += arr[i][j];
            }
        }

        int score2 = 0;
        for (auto i : res2) {
            for (auto j : res2) {
                score2 += arr[i][j];
            }
        }
        
        mn = min(mn, abs(score1 - score2));
    } while (prev_permutation(tmp.begin(), tmp.end()));

    cout << mn << endl;
}

int main() {
    fastio;
    input();
}