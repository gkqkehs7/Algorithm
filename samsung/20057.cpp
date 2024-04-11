#include <iostream>
using namespace std;
int n;
int map[500][500];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int out_sand = 0;

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >=n || y < 0) {
        return false;
    }
    return true;
}

void move_tornado(int x, int y, int direction) {

    // cout << x << " " << y << "\n";
    int sand = map[x][y];
    int sand1 = sand * 0.01;
    int sand2 = sand * 0.02;
    int sand5 = sand * 0.05;
    int sand7 = sand * 0.07;
    int sand10 = sand * 0.1;

    if(direction == 0) {
        // 1퍼 위
        int nx = x - 1;
        int ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 1퍼 아래
        nx = x + 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 2퍼 위
        nx = x - 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 2퍼 아래
        nx = x + 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 7퍼 위
        nx = x - 1;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 7퍼 아래
        nx = x + 1;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 10퍼 위
        nx = x - 1;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 10퍼 아래
        nx = x + 1;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 5퍼
        nx = x;
        ny = y - 2;
        if(check_path(nx, ny)) {
            sand = sand - sand5;
            map[nx][ny] += sand5;
        } else {
            sand = sand - sand5;
            out_sand += sand5;
        }

        // 나머지
        nx = x;
        ny = y - 1;
        if(check_path(nx, ny)) {
            map[nx][ny] += sand;
        } else {
            out_sand += sand;
        }
    } else if(direction == 1) {
        // 1퍼 왼
        int nx = x - 1;
        int ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 1퍼 오
        nx = x - 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 2퍼 왼
        nx = x;
        ny = y - 2;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 2퍼 오
        nx = x;
        ny = y + 2;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 7퍼 왼
        nx = x;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 7퍼 오
        nx = x;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 10퍼 왼
        nx = x + 1;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 10퍼 오
        nx = x + 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 5퍼
        nx = x + 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand5;
            map[nx][ny] += sand5;
        } else {
            sand = sand - sand5;
            out_sand += sand5;
        }

        // 나머지
        nx = x + 1;
        ny = y;
        if(check_path(nx, ny)) {
            map[nx][ny] += sand;
        } else {
            out_sand += sand;
        }
    } else if(direction == 2) {
        // 1퍼 왼
        int nx = x - 1;
        int ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 1퍼 오
        nx = x + 1;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 2퍼 왼
        nx = x - 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 2퍼 오
        nx = x + 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 7퍼 왼
        nx = x - 1;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 7퍼 오
        nx = x + 1;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 10퍼 왼
        nx = x - 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 10퍼 오
        nx = x + 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 5퍼
        nx = x;
        ny = y + 2;
        if(check_path(nx, ny)) {
            sand = sand - sand5;
            map[nx][ny] += sand5;
        } else {
            sand = sand - sand5;
            out_sand += sand5;
        }

        // 나머지
        nx = x;
        ny = y + 1;
        if(check_path(nx, ny)) {
            map[nx][ny] += sand;
        } else {
            out_sand += sand;
        }
    } else if(direction == 3) {
        // 1퍼 왼
        int nx = x + 1;
        int ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 1퍼 오
        nx = x + 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand1;
            map[nx][ny] += sand1;
        } else {
            sand = sand - sand1;
            out_sand += sand1;
        }

        // 2퍼 왼
        nx = x;
        ny = y - 2;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 2퍼 오
        nx = x;
        ny = y + 2;
        if(check_path(nx, ny)) {
            sand = sand - sand2;
            map[nx][ny] += sand2;
        } else {
            sand = sand - sand2;
            out_sand += sand2;
        }

        // 7퍼 왼
        nx = x;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 7퍼 오
        nx = x;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand7;
            map[nx][ny] += sand7;
        } else {
            sand = sand - sand7;
            out_sand += sand7;
        }

        // 10퍼 왼
        nx = x - 1;
        ny = y - 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 10퍼 오
        nx = x - 1;
        ny = y + 1;
        if(check_path(nx, ny)) {
            sand = sand - sand10;
            map[nx][ny] += sand10;
        } else {
            sand = sand - sand10;
            out_sand += sand10;
        }

        // 5퍼
        nx = x - 2;
        ny = y;
        if(check_path(nx, ny)) {
            sand = sand - sand5;
            map[nx][ny] += sand5;
        } else {
            sand = sand - sand5;
            out_sand += sand5;
        }

        // 나머지
        nx = x - 1;
        ny = y;
        if(check_path(nx, ny)) {
            map[nx][ny] += sand;
        } else {
            out_sand += sand;
        }
    }


}

void print_map() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    int start_x = n / 2;
    int start_y = n / 2;

    int move_size = 1;
    int direction = 0;

    while(move_size < n) {
        for(int i=0; i<2; i++) {
            // 토네이도 이동
            for(int j=0; j<move_size; j++) {
                start_x = start_x + dx[direction];
                start_y = start_y + dy[direction];
                move_tornado(start_x, start_y, direction);
                // print_map();
            }

            direction = (direction + 1) % 4;
        }

        // 마지막에는 한번더 이동
        if(move_size == n-1) {
            for(int j=0; j<move_size; j++) {
                start_x = start_x + dx[direction];
                start_y = start_y + dy[direction];
                move_tornado(start_x, start_y, direction);
            }
        }

        move_size++;
    }

    cout << out_sand;
}