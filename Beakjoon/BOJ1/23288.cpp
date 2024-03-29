#include <iostream>
#include <string.h>
using namespace std;

int n, m , k;
int map[21][21] = { 0, };
int direction[4] = { 0, 1, 2, 3 }; // 동 남 서 북
int dice_ver[4] = { 2, 1, 5, 6 };
int dice_hor[3] = { 4, 1, 3 };
int ver = 1;
int hor = 1;

int roll_dice(int direction) {
    if(direction == 3) {
        ver++;
        if(ver == 4) ver = 0;
    } else if (direction == 1) {
        ver--;
        if(ver == -1) ver = 3;
    } else if(direction == 0) {
        hor++;
        if(hor == 3) hor = 0;
    } else if(direction == 2) {
        hor--;
        if(hor == -1) hor = 2;
    }

    if(ver == 0) return dice_ver[2];
    else if(ver == 1) return dice_ver[3];
    else if(ver == 2) return dice_ver[0];
    else if(ver == 3) return dice_ver[1];
}

int dx[4] = { 0, 1, 0, -1};
int dy[4] = {1, 0 ,-1, 0};
bool visited[21][21] = { false, };
int same = 1;

void get_score(int x, int y, int target) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < n && nx >= 0 && ny < m && ny >=0 && visited[nx][ny] == false && map[nx][ny] == target) {
            visited[nx][ny] = true;
            same++; 
            get_score(nx, ny, target);
        }
    }
}

void dfs(int x, int y, int direc) {
    int nx = x;
    int ny = y;
    bool change_direc = false;
    if(direc == 0) {
        nx = x + 1;
        if(nx == n) {
            nx = x - 1;
            change_direc = true;
        }
    } else if(direc == 1) {
        ny = y + 1;
        if(ny == m) {
            ny = y - 1;
            change_direc = true;
        }
    } else if(direc == 2) {
        nx = x - 1;
        if(nx == -1) {
            nx = x + 1;
            change_direc = true;
        }
    } else if(direc == 3) {
        ny = y - 1;
        if(ny == -1) {
            ny = y + 1;
            change_direc = true;
        }
    }

    visited[x][y] = false;
    get_score(x, y, map[x][y]);
    int score = same * map[x][y];
    same = 0;
    memset(visited, false, sizeof(visited));

    int under = roll_dice(ver);
    int next_direc = direc;
    if(under > score) {
        next_direc = direc + 1;
        if(next_direc == 4) next_direc = 0;
    } else if (under < score) {
        next_direc = direc - 1;
        if(next_direc == -1) next_direc = 3;
    }
}

int main() {
  

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }

    dfs(1, 1, 0);
}