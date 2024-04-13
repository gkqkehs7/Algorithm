#include <iostream>

using namespace std;

int n = 5;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int map[5][5] = { {1,2,0,0,5}, {0,0,8,9,10}, {11,12,13,0,0}, {16,17,0,19,0}, {21,22,23,24,25}};

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0) {
        return false;
    }

    return true;
}

int move(int x, int y, int len, int direction) {
    int move_len = n % ((len - 1) * 2);

    int nx = x;
    int ny = y;
    int d = direction;

    for(int i=0; i<move_len; i++) {
        nx = x + dx[d];
        ny = y + dy[d];

        if(!check_path(nx, ny)) {
            // 
        }
    }
} 

void print_map() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {

    map[2][3] = -1;
    print_map();
    
    move(1000);

    print_map();
}