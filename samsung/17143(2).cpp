#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
    int x;
    int y;
    int velocity;
    int direction;
    int size;
};

vector<Shark> map[101][101];
int r, c, m;
int answer = 0;
vector<Shark> sharks;
vector<int> row_max;
vector<int> col_max;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


bool check_path(int x, int y) {
    if(x >= r || x < 0 || y >= c || y < 0) {
        return false;
    }
    return true;
}


void fishing(int y) {
    // 가장 가까운 상어 찾기
    for(int i=0; i<r; i++) {
        if(!map[i][y].empty()) {
            map[i][y].clear();
        }
    }
}

Shark move(Shark shark) {
    int x = shark.x;
    int y = shark.y;
    int v = shark.velocity;
    int d = shark.direction;

    // cout << x << " " << y << " -> ";
    if(d == 0 || d == 1) {
        int rotate = (r - 1) * 2;
        rotate = v % rotate; 

        while(rotate > 0) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(check_path(nx, ny)) {
                x = nx;
                y = ny;
            } else {
                if(d == 0) {
                    d = 1;
                } else if(d == 1) {
                    d = 0;
                } else if(d == 2) {
                    d = 3;
                } else if(d == 3) {
                    d = 2;
                }
                x = x + dx[d];
                y = y + dy[d];
            }
            rotate--;
        }
    } else {
        int rotate = (c - 1) * 2;
        rotate = v % rotate; 

        while(rotate > 0) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(check_path(nx, ny)) {
                x = nx;
                y = ny;
            } else {
                if(d == 0) {
                    d = 1;
                } else if(d == 1) {
                    d = 0;
                } else if(d == 2) {
                    d = 3;
                } else if(d == 3) {
                    d = 2;
                }
                x = x + dx[d];
                y = y + dy[d];
            }
            rotate--;
        }
    }

    return { x, y, shark.velocity, d, shark.size };
}

vector<Shark> sharks_move() {
    vector<Shark> moved_sharks;

    for(int i=0; i<sharks.size(); i++) {
        Shark shark = move(sharks[i]);

        bool live = true;

        // 내가 먹히는지 체크
        for(int j=0; j<moved_sharks.size(); j++) {
            if(shark.x == moved_sharks[j].x && shark.y == moved_sharks[j].y) {
                live = false;
                break;
            }
        }

        if(live) {
            moved_sharks.push_back(shark);
        }
    }

    return moved_sharks;
}


bool compare(Shark s1, Shark s2) {
    return s1.size > s2.size;
}


void sort_sharks_by_size() {
    sort(sharks.begin(), sharks.end(), compare);
}


int main() {
    cin >> r >> c >> m;

    for(int i=0; i<m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.push_back({ r-1, c-1, s, d-1, z });
    }

    sort_sharks_by_size();

    for(int i=0; i<c; i++) {
        // 상어 그리기
        draw_sharks(i+1);

        // 상어 잡기
        vector<Shark> remain_sharks = fishing(i);
        sharks.clear();

        sharks = remain_sharks;

        // cout << "after fising\n";
        // draw_sharks();
        // draw_map();

        // 상어 이동
        vector<Shark> live_sharks = sharks_move();
        sharks.clear();

        sharks = live_sharks;

        // cout << "after move\n";
        // draw_sharks();
        // draw_map();
    }
    cout << answer;
}