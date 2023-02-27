#include <iostream>
#include <string>
using namespace std;

int dp[5001];

int check_alphabet(char first, char second) {
    if(first - '0' == 0 || second - '0' == 0) return 1;
    if(first - '0' < 3) {
        if(first- '0' == 2) {
            if(second - '0' <= 6) {
                return 2;
            } else {
                return 1;
            }
        } else {
            return 2;
        }
    } else {
        return 1;
    }
}

int main() {
    string s;
    cin >> s;   

    bool wrong = false;

    dp[0] = 1;
    if(s[0]-'0' == 0) {
        wrong = true;
    } else {
        if(s[1] - '0' == 0) {
            if(s[0] - '0' > 2) wrong = true;
        }
    }

    dp[1] = check_alphabet(s[0], s[1]);
    
    
    if(s.length() == 0) {
        wrong = true;
    } else {
        for(int i=2; i<s.length(); i++) {
            if(s[i] - '0' == 0) {
                if(s[i-1] - '0' > 2) {
                    wrong = true;
                    break;
                } else {
                    dp[i] = dp[i-2];
                    continue;
                }
            }
            
            if(check_alphabet(s[i-1], s[i-2]) == 1) {
                dp[i] = dp[i-1] % 1000000;
            } else {
                dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
            }
        }
    }

    if(wrong) cout << 0;
    else cout << dp[s.length() - 1];
}