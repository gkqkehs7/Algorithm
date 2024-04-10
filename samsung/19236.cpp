#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish {
    int x;
    int y;
    int number;
    int direction;
    bool live;
};


int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };


// x, y에 있는 물고기 먹기
// bool eat_fish(int x, int y, int map[4][4]) {
//     int fish_number = map[x][y];
//     Fish fish = fishes[fish_number];

//     // 물고기 죽어있는 경우
//     if(!fish.live) {
//         return false;
//     }

//     // 상어가 이동, 물고기 방향 갖기
//     shark_x = x;
//     shark_y = y;
//     shark_direction = fish.direction;

//     // 물고기 먹기
//     fishes[fish_number].live = false;
//     map[x][y] = -1;

//     return true;
// }

bool check_path(int x, int y, int shark_x, int shark_y) {
    if(x >= 4 || x < 0 || y >= 4 || y < 0) {
        return false;
    }

    if(shark_x == x && shark_y == y) {
        return false;
    }

    return true;
}

bool fish_move(int map[4][4], vector<Fish> fishes, int shark_x, int shark_y) {
    for(int i=0; i<fishes.size(); i++) {
        if(!fishes[i].live) {
            continue;
        }

        int x = fishes[i].x;
        int y = fishes[i].y;
        int nx = x;
        int ny = y;

        bool move = false;
        int direction = fishes[i].direction;     
        
        for(int j=0; j<8; j++) {
            direction = (fishes[i].direction + j) % 8;
            nx = x + dx[direction];
            ny = y + dy[direction];

            if(check_path(nx, ny, shark_x, shark_y)) {
                move = true;
                break;
            }
        }
        

        if(move) {
            // cout << fishes[i].number + 1 << "fish direction is " << direction << "\n";
            // cout << fishes[i].number + 1 << "fish move to " << x << "," << y << "->" << nx << "," << ny << "\n";
            int now_fish_number = map[x][y];
            int change_fish_number = map[nx][ny];

            map[nx][ny] = now_fish_number;
            map[x][y] = change_fish_number;

            fishes[change_fish_number].x = x;
            fishes[change_fish_number].y = y;

            fishes[i].x = nx;
            fishes[i].y = ny;
            fishes[i].direction = direction;
        }
    }
}

// void print_map() {
//     for(int i=0; i<4; i++) {
//         for(int j=0; j<4; j++) {
//             if(map[i][j] == -1) {
//                 cout << -1 << " ";
//             } else {
//                 cout << map[i][j] + 1 << " ";
//             }
      
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

bool cango(int map[4][4], int x, int y) {
    if(x >= 4 || x < 0 || y >= 4 || y < 0) {
        return false;
    }

    if(map[x][y] == -1) {
        return false;
    }

    return true;

}

void dfs(int origin_map[4][4], vector<Fish> origin_fishes, int x, int y, int direction) {
    for(int i=1; i<=3; i++) {
        int nx = x + dx[direction] * i;
        int ny = y + dy[direction] * i;

        if(cango(origin_map, nx, ny)) {
            // 배열들 복사
            int copy_map[4][4];
            for(int p=0; p<4; p++) {
                for(int k=0; k<4; k++) {
                    copy_map[p][k] = origin_map[p][k];
                }
            }

            vector<Fish> copy_fishes;
            for(int j=0; j<origin_fishes.size(); j++) {
                copy_fishes.push_back(origin_fishes[j]);
            }

            // 물고기 먹기
            int fish_number = copy_map[nx][ny];
            Fish fish = copy_fishes[fish_number];
    
            int direction = fish.direction;

            copy_fishes[fish_number].live = false;
            copy_map[x][y] = -1;


            // 물고기 이동
            fish_move(copy_map, copy_fishes, nx, ny);
        }
    }
    
}

bool compare(Fish f1, Fish f2) {
    return f1.number < f2.number;
}

int main() {
    vector<Fish> fishes;
    int map[4][4];

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int number, direction;
            cin >> number >> direction;

            fishes.push_back({ i, j, number - 1, direction - 1, true });
            map[i][j] = number - 1;
        }
    }

    sort(fishes.begin(), fishes.end(), compare);

    dfs(map, fishes, 0, 0);
}