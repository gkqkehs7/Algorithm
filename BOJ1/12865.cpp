#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int ,int>> v;
int dp[101][100001] = { 0, };

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int wei, val;
        cin >> wei >> val;
        v.push_back({ wei, val });
    }

    for(int i=1; i<=n; i++) {
        int wei = v[i-1].first;
        int val = v[i-1].second;
        for(int j=1; j<=k; j++) {
            if( j >= wei ) {
                dp[i][j] = max(dp[i-1][j-wei] + val, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }   
        }
    }

    cout << dp[n][k];
}