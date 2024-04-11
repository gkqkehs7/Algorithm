#include <iostream>

using namespace std;

int map[5][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

// 90도 회전
void rotate90(int x, int y, int len) {
    int copy_map[len+1][len+1];

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            copy_map[j][len-i-1] = map[x+i][y+j];
        }
    }

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            map[x+i][y+j] = copy_map[i][j];
        }
    }
}

// 180도 회전
void rotate180(int x, int y, int len) {
    int copy_map[len+1][len+1];

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            copy_map[len-i-1][len-j-1] = map[x+i][y+j];
        }
    }

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            map[x+i][y+j] = copy_map[i][j];
        }
    }
}

// 270도 회전
void rotate270(int x, int y, int len) {
    int copy_map[len+1][len+1];

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            copy_map[len-j-1][i] = map[x+i][y+j];
        }
    }

    for(int i=0; i<len; i++) {
        for(int j=0; j<len; j++) {
            map[x+i][y+j] = copy_map[i][j];
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
    print_map();
    
    rotate270(1, 1, 3);

    print_map();
}