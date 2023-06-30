#include <iostream>
using namespace std;

int dp[1001][1001];

int comb(int n, int k) {
    if(n == k) return 1;
    if(n < k) return 0;
    if(k == 0) return 1;

    if(dp[n][k] == -1) {
        dp[n][k] = ( comb(n-1, k) + comb(n-1, k-1) ) % 10007;
    } 

    return dp[n][k];
}

int main() {
    int n,k;
    cin >> n >> k;

    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << comb(n, k);
}