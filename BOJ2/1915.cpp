#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int map[1001][1001];
int dp[1001][1001];

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;

        for(int j=1; j<=s.length(); j++) {
            map[i][j] = s[j-1] - '0';
        }
    } 

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {

            if(map[i][j] == 1) {
                dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1;
            }       
        }
    }

    int max_ans = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {

            max_ans = max(max_ans, dp[i][j]);     
        }
    }

    cout << max_ans * max_ans;
}