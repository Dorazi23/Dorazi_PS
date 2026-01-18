#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000007
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
string board[15];

bool row[10][10];
bool col[10][10];
bool box[10][10];

bool solved = false;
void func () {
    if (solved) return;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '0') {
                for (int k = 1; k <= 9; k++) {
                    if (!row[i][k] && !col[j][k] && !box[(i/3)*3 + j/3][k]) {
                        board[i][j] = k + '0';
                        row[i][k] = col[j][k] = box[(i/3)*3 + j/3][k] = 1;
                        func();
                        board[i][j] = '0'; 
                        row[i][k] = col[j][k] = box[(i/3)*3 + j/3][k] = 0;
                    }
                }
                return;
            }
        }
    }    

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    solved = true;
}

void input () {
    for (int i = 0; i < 9; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '0') {
                int num = board[i][j] - '0';
                row[i][num] = col[j][num] = box[(i/3)*3 + j/3][num] = 1;
            }
        }
    }
    
    func();
    
}

int main() {
    fastio;
    input();
}