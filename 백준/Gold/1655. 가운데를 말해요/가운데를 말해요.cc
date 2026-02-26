#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 4e17
using namespace std;
using ll = long long;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
int t;

void input () {
    cin >> t;
    while (t--) {
        int n; cin >> n;
        // 1. 최대 힙의 크기는 최소 힙과 같더나 1만큼 커야 함
        if (maxHeap.empty() || maxHeap.size() == minHeap.size() ) {
            maxHeap.push(n);
        }
        else minHeap.push(n);

        // 2. 최대 힙 top <= 최소 힙 top
        if ((!maxHeap.empty() && !minHeap.empty()) && maxHeap.top() > minHeap.top()) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            minHeap.push(a); 
            maxHeap.push(b);
        }

        cout << maxHeap.top() << endl;
    }
}

int main() {
    fastio;
    input();
}