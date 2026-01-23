#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string str;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        stack<char> s;
        string str; int flag = 0;
        getline(cin,str); 
        //cout << str << endl;
        if(str == "."){
            break;
        }
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if(ch == '(' || ch == '['){
                s.push(ch);
            }
            
            if(ch == ')'){ 
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else{
                    flag = 1;
                    break;
                }
            }
            
            if(ch == ']'){ 
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else{
                    flag = 1;
                    break;
                }
            }
                
        }
        if(!s.empty() || flag){
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
    }
}