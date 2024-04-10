#include <iostream>
#include <deque>

using namespace std;

int map[5][5] = { { 1,2,3,4,5}, {6, 7, 8, 9, 10}, {11, 12, 13 ,14, 15}, {16,17,18,19,20}, {21,22,23,24,25}};

void rotate(int x1, int y1, int x2, int y2) {
    
}

void print_map() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    
}