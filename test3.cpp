#include <iostream>

using namespace std;

int n = 5;
int map[5][5] = { {1,2,0,0,5}, {0,0,8,9,10}, {11,12,13,0,0}, {16,17,0,19,0}, {21,22,23,24,25}};

int gravity() {
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 0) {
               	int x = i;
				int y = j;
				while (x > 0 && map[x][y] == 0) x--; // 0이 아닌 곳까지 올라가서
                map[i][j] = map[x][y];  // 그 블럭 가져오기
                map[x][y] = 0; // 그 위치는 빈칸 처리
            }
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
    
    gravity();

    print_map();
}