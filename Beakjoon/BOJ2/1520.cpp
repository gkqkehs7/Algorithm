#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[501][501];
int dp[501][501] = { -1 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
    
    if(x == n-1 && y == m-1) {
        return 1;
    }
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < n && nx >= 0 && ny < m && ny >=0 && map[x][y] > map[nx][ny]) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }
    cout << dfs(0, 0);   
}