#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[501][501];
int dp[501][501] = { 0, };
bool visited[501][501] = { false };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;

void dfs(int x, int y) {
    if(x == n-1 && y == m-1) {
        ans++;
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < n && nx >= 0 && ny < m && ny >=0 && visited[nx][ny] == false && map[x][y] > map[nx][ny]) {
           
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;
        }
    }
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
    dfs(0, 0);

    cout << ans;
}