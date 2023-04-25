#include <iostream>
#include <string>
#include <stack>
using namespace std;
string arr[101];
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        arr[i] = input;
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        stack<char> s;
        string str = arr[i];
        s.push(str[0]);
    
        for(int i=1; i<str.length(); i++) {
    
            if(s.empty()) {
                s.push(str[i]);
            } else {
                if(str[i] == s.top()) {
                    s.pop();
                } else {
                    s.push(str[i]);
                }
            }
            
        }
        if(s.size() == 0) ans++;
        
    }
    cout << ans;

}