#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int t;

struct cmp{
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        if(a.X == b.X){
            return a.Y > b.Y;
        }
        else{
            return a.X > b.X;
        }
    }
};

int main() {
    fastio;
    cin >> t;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    while(t--){
        int n; cin >> n;
        if(n == 0){
            if(!pq.empty()){
                if(pq.top().second == 1){ //양수
                    cout << pq.top().first << endl;    
                }
                else{ //음수
                    cout << (-1) * pq.top().first << endl;
                }
                pq.pop();
            }
            else{
                cout << "0" << endl;
            }
        }
        else{
            if(n > 0){ //양수 일 때
                pq.push({n, 1});
            }
            else{ //음수 일 때
                pq.push({abs(n),0});
            }
        }
    }
}