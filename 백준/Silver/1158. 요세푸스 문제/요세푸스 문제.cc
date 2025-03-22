#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    list<int> lst;
    for (int i = 1; i <= n ;i++ ) {
        lst.push_back(i);
    }
    cout << "<";
    list<int>::iterator iter = lst.begin();
    while(!lst.empty()){
        for (int i = 0; i < k - 1; i++) {
            iter++;
            if(iter == lst.end()){
                iter = lst.begin();
            }
        }
        if(lst.size() == 1){
            cout << *iter;
        }
        else{
            cout << *iter << ", ";
        }
        iter = lst.erase(iter);
        if(iter == lst.end()){
            iter = lst.begin();
        }
    }
    cout << ">";
}