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

bool cmp (string s1, string s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    else { 
        int tmp1 = s1.size(), tmp2 = s2.size();
        int sum1 = 0, sum2 = 0;
        while(tmp1--) {
            if (0 <= s1[tmp1] - '0' && s1[tmp1] - '0' <= 9) {
                sum1 += (s1[tmp1] - '0');
            }
        }

        while(tmp2--) {
            if (0 <= s2[tmp2] - '0' && s2[tmp2] - '0' <= 9) {
                sum2 += (s2[tmp2] - '0');
            }
        }
        
        if (sum1 != sum2) return sum1 < sum2;
        else return s1 < s2;
    }
}

vector<string> slist;
void input() {
    fastio;
    cin >> n;
    while(n--) {
        string t; cin >> t;
        slist.push_back(t);
    }
    sort(slist.begin(), slist.end(), cmp);
    for (auto val : slist) {
        cout << val << endl;
    }
}

int main() {
    input();
}