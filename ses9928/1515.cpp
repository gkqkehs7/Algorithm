#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int now = 0;
    int prev = s[0] - '0';

    for(int i=1; i<s.length(); i++) {
        if(s[i] > prev) {
            continue;
        }
        now++;
    }
}