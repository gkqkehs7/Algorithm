#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000

int map[101][101];
bool visited[101][101][5];
int n, m;
int x, y, direc;
int target_x, target_y, target_direc;
int ans = MAX;

void dfs(int nx, int ny, int nd, int depth) {
    cout << depth << ": " <<nx << " " << ny << " " << nd << "\n";
    if(nx == target_x && ny == target_y && nd == target_direc) {
        ans = min(ans, depth);
        return;
    }
    int next_x = 0;
    int next_y = 0;
    int next_d = 0;

    // 그 방향 유지
    next_d = nd;
    for(int i=0; i<4; i++) {
        if(next_d == 1) {
            next_x = nx;
            next_y = ny + i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 1);
            }
        } else if(next_d == 2) {
            next_x = nx + i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 1);
            }
        } else if(next_d == 3) {
            next_x = nx;
            next_y = ny - i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 1);
            }
        } else if(next_d == 4) {
            next_x = nx - i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 1);
            }
        }
    }

    // 오른쪽 회전
    if(nd == 4) next_d = 1;
    else next_d = nd +  1;
    for(int i=0; i<4; i++) {
        if(next_d == 1) {
            next_x = nx;
            next_y = ny + i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 2) {
            next_x = nx + i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 3) {
            next_x = nx;
            next_y = ny - i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 4) {
            next_x = nx - i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        }
    }

    // 왼쪽 회전
    if(nd == 0) next_d = 3;
    else next_d = nd - 1;
    for(int i=0; i<4; i++) {
        if(next_d == 1) {
            next_x = nx;
            next_y = ny + i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 2) {
            next_x = nx + i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 3) {
            next_x = nx;
            next_y = ny - i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        } else if(next_d == 4) {
            next_x = nx - i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 2);
            }
        }
    }

    // 180도 회전
    if(nd == 3) next_d = 1;
    else if(nd == 4) next_d = 2;
    else next_d = nd + 2;
    for(int i=0; i<4; i++) {
        if(next_d == 1) {
            next_x = nx;
            next_y = ny + i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 3);
            }
        } else if(next_d == 2) {
            next_x = nx + i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 3);
            }
        } else if(next_d == 3) {
            next_x = nx;
            next_y = ny - i;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 3);
            }
        } else if(next_d == 4) {
            next_x = nx - i;
            next_y = ny;

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <= m && visited[next_x][next_y][next_d] == false && map[next_x][next_y] == 0) {
                visited[next_x][next_y][next_d] = true;
                dfs(next_x, next_y, next_d, depth + 3);
            }
        }
    }

}

int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int input; 
            cin >> input;
            map[i][j] = input;

            for(int k=0; k<5; k++) {
                visited[i][j][k] = false;
            }
            
        }
    }

    cin >> x >> y >> direc;
    cin >> target_x >> target_y >> target_direc;  


    dfs(x, y, direc, 0);
    cout << ans;
}