#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
stack<int> s;
vector<int> ans;
int num[1000005];
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = n; i > 0; i--) {
        int input; cin >> input;
        num[i] = input;
    }
    
    for (int i = 1; i <= n; i++) {
        int input = num[i];
        while(!s.empty()){
            if(s.top() > input){
                ans.push_back(s.top());
                break;
            }
            s.pop();
        }
        if(s.empty()){ //stack이 비어있음 
            ans.push_back(-1);
        }
        s.push(input);
    }
    int sz = ans.size() - 1;
    for (int i = sz; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}