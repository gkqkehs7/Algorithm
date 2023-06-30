#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int map[101][101];
int dp[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

queue<pair<int ,int>> q;


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int m, n;
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++) {
            map[i][j] = s[j] - '0';
            dp[i][j] = 1000000000;
        }
    }


    dp[0][0] = 0;
    q.push({ 0, 0 });

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << " " << y << "\n";
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < n && nx >= 0 && ny < m && ny >=0) {
                int plus = 0;
                if(map[nx][ny] == 1) {
                    plus = 1;
                }

                if(dp[nx][ny] > dp[x][y] + plus) {
                    dp[nx][ny] = dp[x][y] + plus;
                    q.push({ nx, ny });
                } 
            }
        }
    }


    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n-1][m-1];
}