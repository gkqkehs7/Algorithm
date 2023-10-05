#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int wid = 0;
int hei = 0;
int answer = 999999999;
int dp[26][26][4];

// 북/남/동/서
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cost, int direction, vector<vector<int>> board) {
    if(x == hei -1 && y == wid - 1) {
        answer = min(cost, answer);
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 && nx < hei && ny >=0 && ny < wid && board[nx][ny] == 0) {
            int nextCost = cost + 100;

            if(direction == 0 || direction == 1) { // 북일때 동/서 거나 남일때 동/서일때
                if(i == 2 || i == 3) {
                    nextCost += 500;
                }
            }

            if(direction == 2 || direction == 3) { // 북일때 동/서 거나 남일때 동/서일때
                if(i == 0 || i == 1) {
                    nextCost += 500;
                }
            }

            if (dp[nx][ny][i] > nextCost) {
                dp[nx][ny][i] = nextCost;
                dfs(nx, ny, nextCost, i, board);
            }
        }
    } 
}

int solution(vector<vector<int>> board) {
    
    hei = board.size();
    wid = board[0].size();
    
    for(int i=0; i<hei; i++) {
        for(int j=0; j<wid; j++) {
            for(int k=0; k<4; k++) {
                dp[i][j][k] = 999999999;
            }
        }
    }

    dfs(0, 0, 0, -1, board);
   
    return answer;
}