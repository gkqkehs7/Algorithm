#include <iostream>
#include <vector>

using namespace std;
int n,m;
int map[51][51];
bool visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4]= { 0, 1, 0, -1 };

void dfs(int r, int c, int d) {

    int nd;
    if(d == 0) {
        nd = 3;
    } else {
        nd = d-1;
    }

    for(int i=0; i<4; i++) {
        int nx = r + dx[nd];
        int ny = c + dy[nd];
        
        if(visited[nx][ny] == false && nx < n && nx >= 0 && ny < m && ny >= 0 && map[nx][ny] != 1) {
            dfs(nx, ny, nd);
        }
    }
   
};

int main() {
    cin >> n >> m;

    int now_r, now_c, now_d;
    cin >> now_r >> now_c >> now_d;


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }

    for(int i=0; i<51; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = false;
        }
    }

    visited[now_r][now_c] = true;
    dfs(now_r, now_c, now_d);
}