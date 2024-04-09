#include <iostream>
#include <vector>
using namespace std;

int n, k;
int map[12][12]; // 발판색깔 저장용
bool game_end = false;

struct Horse {
    int x;
    int y;
    int number;
    int direction;
};

vector<Horse> horses; // 말 순서 저장용
vector<Horse> horse_map[12][12]; // 말 위치 저장용

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0) {
        return false;
    }
    return true;
}

int change_direction(int direction) {
    if(direction == 0) return 1;
    if(direction == 1) return 0;
    if(direction == 2) return 3;
    if(direction == 3) return 2;
}

void move(int horse_number, int x, int y, int direction) {

    cout << "horse_number: " << horse_number << " " << "x: " << x << " " << "y: " << y << "\n";

    vector<Horse> temp;
    int start = horse_map[x][y].size()-1;

    // 해당 칸에 자기 자신까지 번호 찾아서 임시 vector에 stack처럼 쌓기
    for(int i=start; i >= 0; i--) {
        horse_map[x][y].pop_back();
        temp.push_back(horse_map[x][y][i]);

        if(horse_map[x][y][i].number == horse_number) {
            break;
        }
    }

    int nx = x + dx[direction];
    int ny = y + dy[direction];

    if(!check_path(nx, ny) || (check_path(nx, ny) && map[nx][ny] == 2)) {
        direction = change_direction(direction);
        nx = x + dx[direction];
        ny = y + dy[direction];

        if(check_path(nx, ny) || (check_path(nx, ny) && map[nx][ny] == 2)) {
            return;
        }

        if(map[nx][ny] == 0) { // 흰색
            for(int i=0; i<temp.size(); i++) {
                if(i == 0) {
                    temp[i].direction = direction;
                }

                horse_map[nx][ny].push_back(temp[i]);
            }
        } else if(map[nx][ny] == 1) { // 빨강
            for(int i=temp.size()-1; i >= 0; i--) {
                if(i == 0) {
                    temp[i].direction = direction;
                }
                horse_map[nx][ny].push_back(temp[i]);
            }
        }
    } else {
        if(map[nx][ny] == 0) { // 흰색
            for(int i=0; i<temp.size(); i++) {
                horse_map[nx][ny].push_back(temp[i]);
            }
        } else if(map[nx][ny] == 1) { // 빨강
            for(int i=0; i<temp.size(); i++) {
                horse_map[nx][ny].push_back(temp[i]);
            }
        }
    }

    // 마지막에 horses에서도 위치 바꿔주기
    for(int i=0; i<temp.size(); i++) {
        Horse horse = temp[i];

        cout << horse.number << " move to " << horses[horse.number-1].x << " " << horses[horse.number-1].y << " -> " << nx << " " << ny << "\n";

        horses[horse.number-1].x = nx;
        horses[horse.number-1].y = ny;
    }


    // 게임종료
    if(horse_map[nx][ny].size() >= 4) {
        game_end = true;
    }
}

void print_map() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << horse_map[i][j].size() << " ";
        }
        cout << "\n";
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(horse_map[i][j].size() > 0) {
                cout << "(" << i << "," << j << ") -> ";
                for(int k=0; k<horse_map[i][j].size(); k++) {
                    cout << horse_map[i][j][k].number << " ";
                }
                cout << "\n";
            }
        }
    }
    cout << "\n";
}

int main() {
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        horses.push_back({ x - 1, y - 1, i + 1, d - 1 });
        horse_map[x-1][y-1].push_back({ x - 1, y - 1, i + 1, d - 1 });
    }


    int time = 0;
    while(time <= 10) {
        time++;
        for(int i=0; i<horses.size(); i++) {
            move(horses[i].number, horses[i].x, horses[i].y, horses[i].direction);

            if(game_end) {
                cout << time;
                return 0;
            }
            print_map();
        }
    }

    cout << -1;

}