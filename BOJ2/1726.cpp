#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define MAX 1000000000

int map[101][101];
int dp[101][101][5];
int n, m;
int x, y, direc;
int target_x, target_y, target_direc;
int ans = MAX;
queue<tuple<int, int, int>> q;


bool cango(int x_value, int y_value) {
    if(x_value <= n && x_value > 0 && y_value <= m && y_value > 0 && map[x_value][y_value] == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int input;
            cin >> input;
            map[i][j] = input;

            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = MAX;
            }

        }
    }

    // 1 2 3 4 동 남 서 북
    // 1 2 3 4 동 서 남 북

    cin >> x >> y >> direc;
    cin >> target_x >> target_y >> target_direc;

    if (direc == 2) {
        direc = 3;
    }
    else if (direc == 3) {
        direc = 2;
    }

    if (target_direc == 2) {
        target_direc = 3;
    }
    else if (target_direc == 3) {
        target_direc = 2;
    }

    dp[x][y][direc] = 0;
    q.push({x, y, direc});

    while(!q.empty()) {
        int nx = get<0>(q.front());
        int ny = get<1>(q.front());
        int nd = get<2>(q.front());
        // cout << nx << " " << ny << " " << nd << "\n";
        q.pop();

        int next_x;
        int next_y;
        int next_d;

        // turn left
        if(nd == 1) next_d = 4;
        else next_d = nd - 1;
        next_x = nx;
        next_y = ny;

        if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
            dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
            q.push({next_x, next_y, next_d});
        }
        
        // turn right
        if(nd == 4) next_d = 1;
        else next_d = nd + 1;
        next_x = nx;
        next_y = ny;

        if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
            dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
            q.push({next_x, next_y, next_d});
        }
        

        // go
        if(nd == 1) {
            for(int k=1; k<=3; k++) {
                next_x = nx;
                next_y = ny + k;
                next_d = nd;

                if(cango(next_x, next_y)) {
                    if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
                        dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
                        q.push({next_x, next_y, next_d});
                    }
                } else {
                    break;
                }
            }

        } else if(nd == 2) {
            for(int k=1; k<=3; k++) {
                next_x = nx + k;
                next_y = ny;
                next_d = nd;
                if(cango(next_x, next_y)) {
                    if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
                        dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
                        q.push({next_x, next_y, next_d});
                    }
                } else {
                    break;
                }
            }
        } else if(nd == 3) {
            for(int k=1; k<=3; k++) {
                next_x = nx;
                next_y = ny - k;
                next_d = nd;
                if(cango(next_x, next_y)) {
                    if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
                        dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
                        q.push({next_x, next_y, next_d});
                    }
                } else {
                    break;
                }
            }
        } else if(nd == 4) {
            for(int k=1; k<=3; k++) {
                next_x = nx - k;
                next_y = ny;
                next_d = nd;
                if(cango(next_x, next_y)) {
                    if(dp[next_x][next_y][next_d] > dp[nx][ny][nd] + 1) {
                        dp[next_x][next_y][next_d] = dp[nx][ny][nd] + 1;
                        q.push({next_x, next_y, next_d});
                    }
                } else {
                    break;
                }
            }
        }
    }

    cout << dp[target_x][target_y][target_direc];

}