#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1000000000
#define INF 4e18
using namespace std;
using ll = long long;
int n, tot;
vector<int> v;

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
        tot += num;
    }
    sort(v.begin(), v.end());

    int avg = tot / n;
    
    int d = 0, t = 0; // avg+1의 초과량
    for (auto x : v) {
        if (x < avg) {
            d += (avg - x); // 평균보다 낮은 상자 개수
        }
        else if (x > avg+1) {
            t += (x - (avg+1)); // 평균보다 높은 상자 개수 
        }
    }

    cout << max(d, t) << endl;

}

int main() {
    fastio;
    input();
}