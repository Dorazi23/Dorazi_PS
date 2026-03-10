#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
int n, m, answer, arr[10005]; // m: 우주 개수 
int space[105][10005]; // 우주 당 정렬 자리 횟수 

void input () {
    cin >> m >> n; 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) cin >> arr[j];
        for (int j = 0; j < n; j++) {
            space[i][j] = lower_bound(arr, arr+n, arr[j]) - arr;
        }
    }

    // 조합으로 우주 쌍 만들기 
    vector<int> temp;
    for (int i = 0; i < m; i++) {
        if (i <= 1) temp.push_back(1);
        else temp.push_back(0);
    }

    do {
        int a = -1, b = -1;
        for (int i = 0; i < m; i++) {
            if (temp[i]) {
                if (a == -1) a = i;
                else b = i;
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (space[a][i] != space[b][i]) {
                flag = true;
                break;
            }
        }

        if (!flag) answer++;
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << answer << endl;
}

int main() {
    fastio;
    input();
}