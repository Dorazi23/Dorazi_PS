#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> q;
int main() {
    int t;
    string c;
    cin >> t;
    while(t--){
        int num;
        cin >> c;
        if(c=="push"){
            cin >> num;
            q.push(num);
        }
            
        else{
            if(c=="pop"){
                if(q.empty()){
                    cout << "-1\n";
                }
                else{
                    cout << q.front() << '\n';
                    q.pop();
                }
            }
            if(c=="size"){
                cout << q.size() << '\n';
            }
            if(c=="empty"){
                if(q.empty()){
                    cout << "1\n";
                }
                else{
                    cout << "0\n";
                }
            }
            if(c=="front"){
                if(q.empty()){
                    cout << "-1\n";
                }
                else{
                    cout << q.front() << '\n';
                }
            }
            if(c=="back"){
                if(q.empty()){
                    cout << "-1\n";
                }
                else{
                    cout << q.back() << '\n';
                }
            }
        }
    }
}