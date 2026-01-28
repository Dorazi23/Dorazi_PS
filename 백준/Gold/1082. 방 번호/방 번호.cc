#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 4e18
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m, arr[105];
string res;
vector<pair<int,int>> v;

bool cmp (pair<int,int> a, pair<int,int> b) {
    if (a.X == b.X) return a.Y > b.Y; 
    else return a.X < b.X;
}

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        arr[i] = p;
        v.push_back({p, i});
    }
    cin >> m;
    sort(v.begin(), v.end(), cmp);

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (v[0].Y != 0) { // 가장 싼 번호가 0이 아닐 때 
        int cnt = m / v[0].X;
        for (int i = 0; i < cnt; i++) {
            res += to_string(v[0].Y);
        }
        m -= cnt * v[0].X;
    }
    else {
        if (v[1].X > m) { // 두번째 원소를 살 수 없으면 
            cout << 0 << endl;
            return;
        }
        res += to_string(v[1].Y);
        m -= v[1].X;

        int cnt = m / v[0].X;
        for (int i = 0; i < m / v[0].X; i++) {
            res += to_string(v[0].Y);
        }
        m -= cnt * v[0].X;
    }

    for (int i = 0; i < res.size(); i++) {
        int cur_digit = res[i] - '0'; // 현재 번호
        int cur_cost = arr[cur_digit]; // 현재 번호를 사는 데 쓴 비용 
        bool flag = false;
        // 수는 더 크지만 교체 비용이 싼 경우
        for (int j = n-1; j > cur_digit; j--) {
            if (m + cur_cost >= arr[j]) {
                m = m + cur_cost - arr[j];
                res[i] = j + '0';
                flag = true;
                break; // 살 수 있는 가장 큰 수를 골랐으므로 넘어감 
            }
        }        
    }

    cout << res << endl;
}

int main() {
    fastio;
    input();
}