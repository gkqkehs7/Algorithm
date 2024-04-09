#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#define INF 987654321

using namespace std;

int dice[10];
int position[4]; //현재 말 위치

int map[34];
int score[34];
int turn[34];
bool check[34]; //말이 놓여 있는지

int ans;

void init(){
    for (int i = 0; i < 21; i++) map[i] = i+1; //다음 칸으로 이동
    map[21] = 21; //도착 칸
    for (int i = 22; i < 27; i++) map[i] = i+1;
    map[27] = 20;
    map[28] = 29; map[29] = 30; map[30] = 25;
    map[31] = 32; map[32] = 25;

    turn[5] = 22; turn[10] = 31; turn[15] = 28;

    for (int i = 0; i < 21; i++) score[i] = 2 * i;
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26;
    score[31] = 22; score[32] = 24;
}


void dfs(int cnt, int sum){
    if(cnt==10){
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<4; i++){ //말 4개
        int prev = position[i];
        int curr = prev;
        int move_cnt = dice[cnt];

        if(turn[curr] > 0){ //현재 파란색 원에 있다면 방향 전환
            curr = turn[curr];
            move_cnt--;
        }

        while(move_cnt--){
            //남은 칸만큼 이동
            curr = map[curr];
        }

        // 도착 위치가 아닌데, 현재 위치에 다른 말이 있는 경우 -> 고를 수 없음
        if(curr!=21 && check[curr]) continue;

        check[prev] = false;
        check[curr] = true;
        position[i] = curr;

        dfs(cnt+1, sum+score[curr]);

        check[prev] = true;
        check[curr] = false;
        position[i] = prev;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<10; i++){
        cin >> dice[i];
    }

    init();

    dfs(0, 0);

    cout << ans;
}