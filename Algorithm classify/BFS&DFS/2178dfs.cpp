#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
int miro[101][101] = {0};
int visited[101][101] = {false};
int answer[101][101] = { 0 };
int x,y = 0;
int Min = 100001;
int dx[4] = { -1, 0, 1 ,0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x_index, int y_index, int depth) {

    if(x_index == n - 1 && y_index == m - 1) {
        if(depth < Min) {
            Min = depth;
            return;
        }
    }

    for(int i=0; i<4; i++) {
        int nx = x_index + dx[i];
        int ny = y_index + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && miro[nx][ny] == 1) {
            if(visited[nx][ny] == false) {
                visited[nx][ny] = true;
                dfs(nx, ny, depth + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        for(int j=0; j<m; j++) {
            miro[i][j] = s[j] - '0';
        }
    }

    visited[0][0] = true;
    dfs(0,0,1);


    cout << Min;

}