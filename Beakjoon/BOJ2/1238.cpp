#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = 1000000000;
        }
    }

    for(int i=0; i<m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        dp[u][v] = t;
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);   
            }
        }
    }
    

    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans = max(dp[i][x] + dp[x][i], ans);
    }

    cout << ans;
}