#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000

int dx[5] = { 0, 1, 0, -1 };
int dy[5] = { 1, 0, -1, 0};
int dd[4] = { 4, 1, 3, 2 };

int map[101][101];
bool visited[101][101];
int n, m;
int x, y, direc;
int target_x, target_y, target_direc;
int ans = MAX;

void dfs(int nx, int ny, int nd, int depth) {
    if(nx == target_x && ny == target_y && nd == target_direc) {
        if(depth < ans) ans = depth;
        return;
    };

    if(nd == 1) {

    } else if (nd == 2) {
        
    } else if (nd == 3) {

    } else if (nd == 4) {
        
    }
    
    for(int i=0; i<4; i++) {
        
        for(int j=1; j<=3; j++) {
            int next_x = nx + dx[i] * j;
            int next_y = ny + dy[i] * j;
            int next_d = dd[i];

            if(next_x <= n && next_x > 0 && next_y <= n && next_y > 0 && visited[next_x][next_y] == false) {
                visited[next_x][next_y] = true;
                dfs(next_x, next_y, next_d, depth + 1);
            }
        }

        dfs(nx, ny, dd[i], depth + 1);
    }



}

int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int input; 
            cin >> input;
            map[i][j] = input;
            visited[i][j] = false;
        }
    }

    cin >> x >> y >> direc;
    cin >> target_x, target_y, target_direc;   

}