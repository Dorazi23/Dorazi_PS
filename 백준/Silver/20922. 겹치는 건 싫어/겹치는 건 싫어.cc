#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, k, answer, arr[200005], num[100005];

void input () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, en = 0;
    while (st <= en && en < n) {
        int tar = arr[en];
        if (num[tar] < k) {
            num[tar]++;
            en++;
        }
        else {
            num[arr[st]]--;
            st++;
        }

        answer = max(answer, en-st);
    }

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}