#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int m, n;
int map[101][101];
int dp[101][101][5];
vector<pair<int, int>> laser;
queue<tuple<int, int, int>> q;

bool cango(int x, int y) {
    if(x < n && x >= 0 && y < m && y >= 0 && map[x][y] == 0) return true;
    else return false;
}

int main() {
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        for(int j=0; j<s.length(); j++) {
            if(s[j] == '.') {
                map[i][j] = 0;
            } else if(s[j] == '*') {
                map[i][j] = 1;
            } else if(s[j] == 'C') {
                map[i][j] = 0;
                laser.push_back({ i, j });
            }
        }
    }

    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            for(int k=0; k<5; k++) {
                dp[i][j][k] = 1000000000;   
            }
            
        }
    }

      // 동1 남2 서3 북4
    for(int i=1; i<=4; i++) {
        q.push({ laser[0].first, laser[0].second, i });
        dp[laser[0].first][laser[0].second][i] = 0;
    }

    while(!q.empty()) {

        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        int nx, ny, nd;

        //not turn
        nd = d;
        if(nd == 1) {
            nx = x;
            ny = y + 1;
            if(cango(nx,ny)) {
                if(dp[nx][ny][nd] > dp[x][y][d]) {
                    dp[nx][ny][nd] = dp[x][y][d];
                    q.push({ nx, ny, nd });
                }  
            }
        } else if(nd == 2) {
            nx = x + 1;
            ny = y;
            if(cango(nx,ny)) {
                if(dp[nx][ny][nd] > dp[x][y][d]) {
                    dp[nx][ny][nd] = dp[x][y][d];
                    q.push({ nx, ny, nd });
                }  
            }       
        } else if(nd == 3) {
            nx = x;
            ny = y - 1;
            if(cango(nx,ny)) {
                if(dp[nx][ny][nd] > dp[x][y][d]) {
                    dp[nx][ny][nd] = dp[x][y][d];
                    q.push({ nx, ny, nd });
                }  
            }
        } else if(nd == 4) {
            nx = x - 1;
            ny = y;
            if(cango(nx,ny)) {
                if(dp[nx][ny][nd] > dp[x][y][d]) {
                    dp[nx][ny][nd] = dp[x][y][d];
                    q.push({ nx, ny, nd });
                }  
            }
        }
        
        //turn left
        if(d == 1) nd = 4;
        else nd = d - 1;
        if(dp[x][y][nd] > dp[x][y][d] + 1) {
            dp[x][y][nd] = dp[x][y][d] + 1;
            q.push({ x, y, nd });
        }

        //turn right
        if(d == 4) nd = 1;
        else nd = d + 1;

        if(dp[x][y][nd] > dp[x][y][d] + 1) {
            dp[x][y][nd] = dp[x][y][d] + 1;
            q.push({ x, y, nd });
        }
        
    }

    int ans = 1000000000;
    for(int i=1; i<5; i++) {
        ans = min(ans, dp[laser[1].first][laser[1].second][i]);
    }

    cout << ans;

}