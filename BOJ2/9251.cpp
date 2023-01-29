#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1002][1002];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
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

    // for(int i=1; i <= s1.length(); i++) {
            
    //     for(int j=1; j<= s2.length(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    
    cout << dp[s1.length()][s2.length()];
}