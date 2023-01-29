#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
int dp[1002][1002];
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string ans = "";

    for(int i=0; i<1002; i++) {
        for(int j=0; j<1002; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i=1; i <= s1.length(); i++) {
            
        for(int j=1; j <= s2.length(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
           
        }
    }
    
    int i = s1.length();
    int j = s2.length();

    while(dp[i][j] != 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else if(dp[i][j] == dp[i][j-1]) {
            j--;
        } else if(dp[i][j] == dp[i-1][j-1] + 1) {
            ans += s1[i-1];
            i--;
            j--;
        }
    }
    cout << ans.length() << "\n";

    for(int i=ans.length() -1; i >= 0; i--) {
        cout << ans[i];
    }
   
}