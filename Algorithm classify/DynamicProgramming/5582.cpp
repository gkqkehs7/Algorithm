#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for(int i=0; i<4001; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    int ans = 0;
    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1] == s2[j-1]) {
                if(s1[i-2] == s2[j-2]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i=0; i<=s1.length(); i++) {
    //     for(int j=0; j<=s2.length(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    cout << ans;
}