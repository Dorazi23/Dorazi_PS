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
stack<int> st;
int order = 1;

void input() {
    fastio; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!st.empty()) {
            while(!st.empty() && st.top() == order) {
                st.pop();
                order++;
            }
        }
        
        int num; cin >> num;
        if (num == order) { // 주어진 숫자가 순서와 같을 때
            order++;
            continue;
        }
        else {
            st.push(num);
        }
    }

    while(!st.empty()) {
        auto cur = st.top(); st.pop();
        if (cur == order) order++;
        else {
            cout << "Sad" << endl;
            return;
        }
    }
    cout << "Nice" << endl;
    return;
}

int main() {
    input();
}