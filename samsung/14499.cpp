#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
vector<vector<int>> map;
vector<int> commands;
int dice[6];

bool check_validate_path(int nx, int ny) {
    if(nx >= n || nx < 0 || ny >= m || ny < 0) {
        return false;
    }
    return true;
}

int move_right(int nx, int ny) {
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = temp;

    cout << dice[0] << "\n";

    return dice[1];
}

int move_left(int nx, int ny) {
    int temp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = temp;

    cout << dice[0] << "\n";

    return dice[1];
}

int move_up(int nx, int ny) {
    int temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = temp;

    cout << dice[0] << "\n";

   return dice[1];
}


int move_down(int nx, int ny) {
    int temp = dice[0];
 	dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = temp;

    cout << dice[0] << "\n";

    return dice[1];
}

void print(int nx, int ny, int bottom) {
    if(map[nx][ny] == 0) {
        map[nx][ny] = bottom;
    } else {
        dice[1] = map[nx][ny];
        map[nx][ny] = 0;
    }
}

int main() {
    cin >> n >> m >> x >> y >> k;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        map.push_back(temp);
    }

    for(int i=0; i<k; i++) {
        int input;
        cin >> input;
        commands.push_back(input);
    }

    for(int i=0; i<k; i++) {
        int command = commands[i];

        if(command == 1) {
            int nx = x;
            int ny = y + 1;

            if(check_validate_path(nx, ny)) {
                int bottom = move_right(nx, ny);
                print(nx, ny, bottom);
                x = nx;
                y = ny;
            }

        } else if(command == 2) {
            int nx = x;
            int ny = y - 1;

            if(check_validate_path(nx, ny)) {
                int bottom = move_left(nx, ny);
                print(nx, ny, bottom);
                x = nx;
                y = ny;
            }
        } else if(command == 3) {
            int nx = x - 1;
            int ny = y;

            if(check_validate_path(nx, ny)) {
                int bottom = move_up(nx, ny);
                print(nx, ny, bottom);
                x = nx;
                y = ny;
            }
        } else if(command == 4) {
            int nx = x + 1;
            int ny = y;

            if(check_validate_path(nx, ny)) {
                int bottom = move_down(nx, ny);
                print(nx, ny, bottom);
                x = nx;
                y = ny;
            }
        }
    }
}