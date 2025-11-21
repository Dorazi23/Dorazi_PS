#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000
#define INF 0x3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int t;

void input() {
    fastio;
    cin >> t;
    while (t--) {
        deque<int> num; // 숫자를 저장할 벡터
        string cmd; cin >> cmd; // 명령 문자열
        int n; cin >> n; // 수의 개수
        string arr; cin >> arr; // 숫자 배열
        bool rev_flag = 0;

        // pop의 개수
        int D_cnt = 0;
        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'D') D_cnt++;
        }

        // 수의 개수보다 pop이 많으면 error
        if (n < D_cnt) { 
            cout << "error" << endl;
            continue;
        }   
        
        // 순수한 숫자 문자열
        if (n != 0) {
            string number = ""; 
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] == ',' || arr[i] == ']') { // 쉼표를 만나면 지금까지 쌓아둔 것을 
                    num.push_back(stoi(number));
                    number = "";
                }
                else {
                    number += arr[i];
                }
            }
        }
        
        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'R') {
                rev_flag = !rev_flag;
            }
            else { 
                if (!rev_flag) num.pop_front();
                else num.pop_back();
            }
        }
        
        cout << "[";
        if (!rev_flag) {
            for (int i = 0; i < num.size(); i++) {
                if (i == num.size() - 1) cout << num[i];
                else cout << num[i] << ",";
            }
        }
        else {
            for (int i = num.size()-1; i >= 0; i--) {
                if (i == 0) cout << num[i];
                else cout << num[i] << ",";
            }
        }
        cout << "]" << endl;
    }
}


int main() {
    input();
}