#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;

    int ptr = 0;
    for(int i=1; i<=30000; i++) {
        string str_num = to_string(i);
        for(int j=0; j<str_num.length(); j++) {
            if(str_num[j] == s[ptr]) {
                ptr++;
            }

            if(ptr == s.length()) {
                cout << str_num;
                return 0;
            }
        }
    }
    return 0;
}