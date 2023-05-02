#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int dp[101][10001];
int coin[101];

int main() {
    int n, k;
    cin >> n >> k;

    
    for(int i=1; i<=n; i++) cin >> coin[i];
    sort(coin + 1, coin + n + 1);


    for(int i=0; i<= n; i++) {
        for(int j=0; j<= k; j++) {
            dp[i][j] = MAX;
        }
    }

    for(int i=0; i<=k; i++) {
        if(i % coin[1] == 0) {
            dp[1][i] = i / coin[1];
        }
    }

    for(int i=2; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if(j < coin[i]) {
                dp[i][j] = dp[i-1][j];
            } else if(j >= coin[i]) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]] + 1);
            } 
        }
    }


    // for(int i=1; i<= n; i++) {
    //     for(int j=0; j<= k; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(dp[n][k] == MAX) cout << -1;
    else cout << dp[n][k];
   
    
}
