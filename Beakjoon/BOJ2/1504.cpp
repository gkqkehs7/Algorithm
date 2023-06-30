#include <iostream>
#include <algorithm>
using namespace std;

long long dp[801][801];
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, e, target1, target2;
    cin >> n >> e;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    cin >> target1 >> target2;

    for(int k=1; k <= n; k++) {
        for(int i=1; i <= n; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    // if(dp[target1][target2] == INF) {
    //     cout << -1;
    // } else if(dp[1][target1] == INF || dp[target2][n] == INF) {
    //     if(dp[1][target2] == INF || dp[target1][n] == INF) {
    //         cout << -1;
    //     } else {
    //         cout << dp[1][target2] + dp[target1][target2] + dp[target1][n];
    //     }
    // } else {
    //     long long case1 = dp[1][target1] + dp[target1][target2] + dp[target2][n];
    //     long long case2 = dp[1][target2] + dp[target1][target2] + dp[target1][n];
    //     long long ans = min(case1, case2);

    //     if(ans > 1e9) cout << -1;
    //     else cout << ans;
    // }
    
    long long case1 = dp[1][target1] + dp[target1][target2] + dp[target2][n];
    long long case2 = dp[1][target2] + dp[target1][target2] + dp[target1][n];
    long long ans = min(case1, case2);

    if(ans >= INF) cout << -1;
    else cout << ans;
       
}