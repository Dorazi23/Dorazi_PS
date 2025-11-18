#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int n, m;
vector<pair<int,int>> A, B;

bool cmp (pair<int,int> a, pair<int,int> b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X > b.X;
}

void input () {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        A.push_back({num, i});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        B.push_back({num, i});
    }
}

vector<int> ans;
void output() {
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);

    int idxA = 0, idxB = 0, limita = 0, limitb = 0;
    while (idxA < n && idxB < m) {
        // 값이 같고, 싱힌산 너머에 존재하는 값만 추출
        if (A[idxA].X > B[idxB].X) idxA++;
        else if (A[idxA].X < B[idxB].X) idxB++;
        else {
            if (limita > A[idxA].Y) {
                idxA++;
                continue;
            }
            if (limitb > B[idxB].Y) {
                idxB++;
                continue;
            }
            // 상한선을 정해야 함
            limita = A[idxA].Y; 
            limitb = B[idxB].Y;
            ans.push_back(A[idxA].X);
            idxA++; idxB++;
        }
    }

    cout << ans.size() << endl;
    for (auto val : ans) {
        cout << val << " ";
    }
}

int main() {
    input();
    output();
}