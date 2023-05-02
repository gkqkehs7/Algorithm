#include <iostream>
#include <string>
using namespace std;

int dp[5001];

int to_int(char c1, char c2) {
    if(c1 - '0' == 0) return -1;
    if(c2 - '0' == 0) {
        if(c1 - '0' > 2) {
            return 0;
        } else {
            return -2;
        }
    } 

    return (c1 - '0') * 10 + (c2 - '0');
}

int main() {
    string s;
    cin >> s;   
    bool wrong = false;

    dp[0] = 1;
    if(to_int(s[0], s[1]) > 26) {
        dp[1] = 2;
    } else {
        dp[1] = 1;
    }  

    for(int i=2; i<s.length(); i++) {
        int prev = to_int(s[i-1], s[i-2]);

        if(prev == 0) {
            wrong = true;
            break;
        } 
        
        if(prev == -1) {
            
        } else if(prev == -2) {
            dp[i] = dp[i-1];
        }
        else {
            if(prev > 26) {
            dp[i] = dp[i-1];
            } else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }

        
    } 
    
    
    
}