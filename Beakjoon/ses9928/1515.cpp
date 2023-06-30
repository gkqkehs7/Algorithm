#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int now = 0;
    int prev = s[0] - '0';
    int now_count = 1;

    for(int i=1; i<s.length(); i++) {
        if(s[i] - '0' > prev) {
            now_count++;
            prev = s[i] - '0';
            continue;
        } else { // 줄어든 경우
            if(s[i] - '0' == now && ) { // 줄어들었는데 앞에 자리수와 같고

            } else{
                now++;
            }
        }
    }
}