#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char cookie[1001][1001];

    bool first = true;
    int head_x, head_y, heart_x, heart_y;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char c;
            cin >> c;

            cookie[i][j] = c;
            
            if(c == '*') {
                if(first) {
                    head_x = i;
                    head_y = j;
                    first = false;
                }
            }
        }
    }

    heart_x = head_x + 1;
    heart_y = head_y;

    int left_hand, right_hand, left_leg, right_leg, body = 0;

    // 왼쪽 팔 구하기
    int temp = heart_y - 1;
    while(cookie[heart_x][temp] == '*') {
        temp--;
        left_hand++;
    }

    // 오른쪽 팔 구하기
    temp = heart_y + 1;
    while(cookie[heart_x][temp] == '*') {
        temp++;
        right_hand++;
    }

    // 몸통 구하기
    temp = heart_x + 1;
    while(cookie[temp][heart_y] == '*') {
        temp++;
        body++;
    }

    int body_end_x = heart_x + body;

    // 왼쪽 다리
    temp = body_end_x + 1;
    while(cookie[temp][heart_y - 1] == '*') {
        temp++;
        left_leg++;
    }


    // 오른쪽 다리
    temp = body_end_x + 1;
    while(cookie[temp][heart_y + 1] == '*') {
        temp++;
        right_leg++;
    }

    cout << heart_x + 1 << " " << heart_y + 1 << "\n";
    cout << left_hand << " " << right_hand << " " << body << " " << left_leg << " " << right_leg;
}