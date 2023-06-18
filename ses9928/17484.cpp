#include <iostream>
using namespace std;

int n, m;
int space[10][10];
int dp[10];
int answer = 99999999;

// direction 0 왼쪽 / 1 아래 / 2 오른쪽
void dfs(int depth, int now, int direction, int cost) {
    if(depth == n + 1) {
        if(cost < answer) {
            answer = cost;
        }
        return;
    }

    if(direction == 0) {
        dfs(depth + 1, now, 1, cost + space[depth][now]);

        if(now + 1 < m) {
            dfs(depth + 1, now + 1, 2, cost + space[depth][now]);
        }
        
    } else if(direction == 1) {
        if(now - 1 >= 0) {
            dfs(depth + 1, now - 1, 0, cost + space[depth][now]);
        }
        
        if(now + 1 < m) {
            dfs(depth + 1, now + 1, 2, cost + space[depth][now]);
        }
        
    } else if(direction == 2) {
        if(now - 1 >= 0) {
            dfs(depth + 1, now - 1, 0, cost + space[depth][now]);
        }
        
        dfs(depth + 1, now, 1, cost + space[depth][now]);
    }
    
      
}

int main () {

    cin >> n >> m;
    
    for(int i=0; i<10; i++) dp[i] = 99999999;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            cin >> space[i][j];
        }
    }

    for(int i=0; i < m; i++) {
        dfs(1, i, 0, 0);
        dfs(1, i, 1, 0);
        dfs(1, i, 2, 0);
    }

    cout << answer;
}