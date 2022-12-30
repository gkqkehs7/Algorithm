#include <iostream>
#include <vector>

using namespace std;
int n, m;
int map[51][51];
bool visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int clean_count = 0;
int total_clean = 1;
bool can_clean = true;
bool can_go = true;
void dfs(int r, int c, int d) {

    // cout << r << " " << c << " " << d << "\n\n";
    int nx, ny, nd;

    if (clean_count == 4) {
        clean_count = 0;
        if (d == 0) {
            nx = r + 1;
            ny = c;
            if (nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == 1) {
                can_go = false;
                return;
            }
            else {
                return dfs(nx, ny, d);
            }
        }
        else if (d == 1) {
            nx = r;
            ny = c - 1;

            if (nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == 1) {
                can_go = false;
                return;
            }
            else {
                return dfs(nx, ny, d);
            }
        }
        else if (d == 2) {
            nx = r - 1;
            ny = c;

            if (nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == 1) {
                can_go = false;
                return;
            }
            else {
                return dfs(nx, ny, d);
            }
        }
        else {
            nx = r;
            ny = c + 1;

            if (nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == 1) {
                can_go = false;
                return;
            }
            else {
                return dfs(nx, ny, d);
            }
        }
    }

    if (d == 0) {
        nd = 3;
    }
    else {
        nd = d - 1;
    }


    nx = r + dx[nd];
    ny = c + dy[nd];

    if (visited[nx][ny] == false && nx < n && nx >= 0 && ny < m && ny >= 0 && map[nx][ny] != 1) {
        total_clean++;
        clean_count = 0;
        visited[nx][ny] = true;
        return dfs(nx, ny, nd);
    }
    else {
        clean_count++;
        return dfs(r, c, nd);
    }


};

int main() {
    cin >> n >> m;

    int now_r, now_c, now_d;
    cin >> now_r >> now_c >> now_d;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

    visited[now_r][now_c] = true;
    dfs(now_r, now_c, now_d);

    cout << total_clean;
}