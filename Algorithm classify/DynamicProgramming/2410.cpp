#include <iostream>
#include <cmath>
using namespace std;

int dp[21][1000001];

int main() {
    int n;
    cin >> n;   

    for(int i=0; i<1000001; i++) dp[0][i] = 0;
    for(int i=0; i<21; i++) dp[i][0] = 1;
    
    int limit = 1;
    while(true) {
        if(pow(2, limit) <= n) {
            limit++;
        } else {
            break;
        }
    }


    for(int i=1; i<=limit; i++) {
        int temp = pow(2, i-1);
        for(int j=1; j<=n; j++) {
            if(j < temp) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = (dp[i][j-temp] + dp[i-1][j]) % 1000000000;
            }
        }
    }

    cout << dp[limit][n];
} 