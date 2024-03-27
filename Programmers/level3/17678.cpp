#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> map;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int answer = 999999999;

bool check_validate_path(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }

    if(map[x][y] != '.') {
        return false;
    }

    return true;
}

bool hole_in_one(int x, int y) {
    if(map[x][y] == 'O') {
        return true;
    }

    return false;
}

pair<int,int> move_red(int rx, int ry, int bx, int by, int dx, int dy) {
    int nrx = rx;
    int nry = ry;
    while(check_validate_path(rx, ry) && rx != bx && ry != by) {
        nrx = rx + dx;
        nry = ry + dy;

        if(hole_in_one(nrx, nry)) {
            return make_pair(-1, -1);
        }
    }
    return make_pair(nrx, nry);
}

pair<int,int> move_blue(int rx, int ry, int bx, int by, int dx, int dy) {
    int nbx = bx;
    int nby = by;
    while(check_validate_path(bx, by) && rx != bx && ry != by) {
        nbx = bx + dx;
        nby = by + dy;

        if(hole_in_one(nbx, nby)) {
            return make_pair(-1, -1);
        }
    }
    return make_pair(nbx, nby);
}

void dfs(int rx, int ry, int bx, int by, int depth) {

    if(depth == 10) {
        return;
    }

    for(int i=0; i<4; i++) {
        if(i == 0) { // 오른쪽으로 갈때
            // 오른쪽에 있는게 먼저
            if(ry > by) {
                pair<int,int> nr = move_red(rx, ry, bx, by, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;

                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }

                pair<int,int> nb = move_blue(nrx, nry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            } else {
                pair<int,int> nb = move_blue(rx, ry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }

                pair<int,int> nr = move_red(rx, ry, nbx, nby, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;
                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            }

        } else if(i == 1) { // 아래로 갈때
            // 아래에 있는게 먼저
            if(rx > bx) {
                pair<int,int> nr = move_red(rx, ry, bx, by, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;
                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }

                pair<int,int> nb = move_blue(nrx, nry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            } else {
                pair<int,int> nb = move_blue(rx, ry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }
                pair<int,int> nr = move_red(rx, ry, nbx, nby, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;
                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }

                dfs(nrx, nry, nbx, nby, depth + 1);
            }
        } else if(i == 2) { // 왼쪽으로 갈때
            // 왼쪽에 있는게 먼저
            if(ry > by) {
                pair<int,int> nb = move_blue(rx, ry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }

                pair<int,int> nr = move_red(rx, ry, nbx, nby, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;

                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            } else {
                pair<int,int> nr = move_red(rx, ry, bx, by, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;

                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }

                pair<int,int> nb = move_blue(nrx, nry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            }
        } else if(i == 3) { // 위로갈때
            // 위에 있는게 먼저
            if(rx > bx) {
                pair<int,int> nb = move_blue(rx, ry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }

                pair<int,int> nr = move_red(rx, ry, nbx, nby, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;

                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            } else {
                pair<int,int> nr = move_red(rx, ry, bx, by, dx[i], dy[i]);
                int nrx = nr.first;
                int nry = nr.second;

                if(nrx == -1 && nry == -1) {
                    answer = min(answer, depth);
                    return;
                }
                pair<int,int> nb = move_blue(nrx, nry, bx, by, dx[i], dy[i]);
                int nbx = nb.first;
                int nby = nb.second;
                if(nbx == -1 && nby == -1) {
                    return;
                }
                dfs(nrx, nry, nbx, nby, depth + 1);
            }
        }
    }
}

int main() {
    // 가로 세로
    cin >> n >> m;

    // 시작 지점
    int rx, ry, bx, by;

    for(int i=0; i<n; i++) {
        vector<char> temp;
        for(int j=0; j<m; j++) {
            char input;
            cin >> input;
            if(input == 'R') {
                rx = i;
                ry = j;
            } else if(input == 'B') {
                bx = i;
                by = j;
            }
            temp.push_back(input);
        }
        map.push_back(temp);
    }

    dfs(rx, ry, bx, by, 0);

    cout << answer;
}