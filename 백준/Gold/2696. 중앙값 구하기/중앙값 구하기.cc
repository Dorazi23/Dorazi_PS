#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;

int main() {
    fastio;
    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        vector<int> v;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < m; i++) {
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
            
            if(i % 2 == 0) v.push_back(maxHeap.top()); 
        }
        cout << v.size() << endl;
        for (auto val : v) {
            cout << val << " ";
        }
        cout << endl;
    }
}