#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

int main() {
    fastio;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(maxHeap.empty() || n <= maxHeap.top()){
            maxHeap.push(n);
        }
        else{
            minHeap.push(n);
        }
        
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << endl;
    }
}