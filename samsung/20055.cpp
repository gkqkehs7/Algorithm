#include <iostream>

using namespace std;
int n, k;

int map[2][101];
int robots[101];

void rotate() {
    int temp1 = map[0][n-1];
    // 위쪽
    for(int i=n-1; i>0; i--) {
        map[0][i] = map[0][i-1];
    }

    int temp2 = map[1][0];
    // 아래쪽
    for(int i=0; i<n-1; i++) {
        map[1][i] = map[1][i+1];
    }
    map[1][n-1] = temp1;
    map[0][0] = temp2;

    for(int i=n-1; i>0; i--) {
        robots[i] = robots[i-1];
    }

    // 끝에 있는건 내리고 앞쪽에 있는건 옮기기
    robots[n-1] = 0;
    robots[0] = 0;
}

void lift_up() {
    if(map[0][0] > 0) {
        map[0][0] -= 1;
        robots[0] = 1;
    }
}

void move_robot() {
    for(int i=n-2; i>=0; i--) {
        if(robots[i] == 1) { // 해당 칸에 로봇이 있고
            if(map[0][i+1] > 0) { // 내구도가 있는가
                if(robots[i+1] == 0) { // 옮기려는 칸에 로봇이 없는가
                    map[0][i+1] -= 1;
                    robots[i+1] = 1; // 로봇 옮기고
                    robots[i] = 0; // 이전꺼 지우고
                }
                
            }
        }
    }
}

void print_map()  {
    cout << "<tables>\n";
    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
 
    cout << "<robots>\n";
    for(int i=0; i<n; i++) {
        cout << robots[i] << " ";
    }
    cout << "\n\n";
}

int check_end() {
    int zero = 0;
    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 0) zero++;
        }
    }

    return zero;
}

int main() {
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> map[0][i];
    }

    for(int i=n-1; i>=0; i--) {
        cin >> map[1][i];
    }

    for(int i=0; i<n; i++) {
        robots[i] = 0;
    }

    int time = 0;
    while(true) {
        time++;

        // cout << "------" << time << "-------\n";
        // cout << "rotate!\n";
        rotate();
        // print_map();

        // cout << "move!\n";
        move_robot();
        // print_map();


        // cout << "lift!\n";
        lift_up();
        // print_map();

   
        int zero = check_end();
        if(zero >= k) {
            break;
        }

    }
    

    cout << time;
}

