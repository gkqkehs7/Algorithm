#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int miro[101][101] = {0};
int visited[101][101] = {false};
int answer[101][101] = { 0 };
int dx[4] = { -1, 0, 1 ,0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        for(int j=0; j<m; j++) {
            miro[i][j] = s[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = true;
    answer[0][0] = 1;
  
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && miro[nx][ny] == 1) {
                if(visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    answer[nx][ny] = answer[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }


    cout << answer[n-1][m-1];

}