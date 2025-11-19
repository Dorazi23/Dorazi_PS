#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int Left[1000005];
int Right[1000005];

void postorder(int cur) {
    if (cur == 0) return;
    if (Left[cur] == 0 && Right[cur] == 0) {
        cout << cur << endl;
        return;
    }
    postorder(Left[cur]);
    postorder(Right[cur]);
    cout << cur << endl;
    return;
}

void input() {
    fastio;
    int root; cin >> root;

    int num;
    while(cin >> num) {
        int st = root;
        while (1) {
            if (num < st) {
                if (Left[st] == 0) { // 왼쪽 자식이 비어있으면
                    Left[st] = num;
                    break;
                }
                else {
                    st = Left[st];
                }
            }
            if (num > st){ 
                if (Right[st] == 0) { // 오른쪽 자식이 비어있으면
                    Right[st] = num;
                    break;
                }
                else {
                    st = Right[st];
                }
            }
        }
    }

    postorder(root);
}

int main() {
    input();
}
