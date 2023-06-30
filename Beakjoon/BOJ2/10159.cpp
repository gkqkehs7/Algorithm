#include <iostream>
using namespace std;
int dp[101][101];

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = -1;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
        dp[b][a] = 2;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][k] == 1 && dp[k][j] == 1) {
                    dp[i][j] = 1;
                }

                if(dp[i][k] == 2 && dp[k][j] == 2) {
                    dp[i][j] = 2;
                }
            }
        }
    }

    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(dp[i][j] == -1) cnt++;
        }
        cout << cnt << "\n";
    }

}