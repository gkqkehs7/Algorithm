#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    int testcase = 1;
    while(true) {
        int n;
        cin >> n;

        if(n == 0) break;

        queue<pair<int ,int>> q;
        int map[126][126];
        int dp[126][126];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int input;
                cin >> input;
                map[i][j] = input;
                dp[i][j] = 1000000000;
            }
        }
        q.push({ 0, 0 });
        dp[0][0] = map[0][0];

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < n && nx >= 0 && ny < n && ny >=0) {
                   if(dp[nx][ny] > dp[x][y] + map[nx][ny]) {
                        dp[nx][ny] = dp[x][y] + map[nx][ny];
                        q.push({ nx, ny });
                   }
                }
            }
        }
        
        cout << "Problem " << testcase << ": " << dp[n-1][n-1] << "\n"; 
        testcase++;
    }
}