#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int s, p, answer, arr[15], has[15];
string str;

int matching (char ch) {
    if (ch == 'A') return 0;
    else if (ch == 'C') return 1;
    else if (ch == 'G') return 2;
    else return 3;
}

void input () {
    cin >> s >> p >> str; 
    for (int i = 0; i < 4; i++) cin >> arr[i];
    // ACGT 개수 

    for (int i = 0; i < p; i++) has[matching(str[i])]++;

    auto check = [&] () -> bool {
        for (int i = 0; i < 4; i++) {
            if (has[i] < arr[i]) return false;
        }
        return true;
    };

    if (check()) answer++;

    for (int i = p; i < s; i++) {
        has[matching(str[i])]++;         
        has[matching(str[i-p])]--; 
        if (check()) answer++;
    }
    
    cout << answer << endl;
}

int main() {
    fastio;
    input();
}