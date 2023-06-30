#include <iostream>
#include <cmath>
using namespace std;

long long dp[1002] = { 0, };

int main() {
    int n;
    cin >> n;

    
    dp[1] = 1;
    dp[2] = 3;

    for(int i=3; i <= n; i++ ) {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }

    cout << dp[n];
    
}