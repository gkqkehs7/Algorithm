#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, d1_start, d2_start;
int arr[21];
int dp[21][21][21];

// 1. 매 턴 마다 비교해서 가장 가까운 문을 찾는다
// 2. 매번 가까운 문을 찾는게 가장 잘 최소일까?
// 3. 모든 경우를 따져서 가장 최소 경로를 찾아야 겠구나
// 4. 모든 경우를 따질때 미리 따진건 스킵해도 되지않을까? -> 깊이, d1, d2가 같다면 그 다음 값도 같을 것이기 때문이야
// 5. 그리고 보통 개수 작으면 3차원 dp생각

int dfs(int depth, int d1, int d2) {
    if(depth == m) {
        return 0;
    }
    
    if(dp[depth][d1][d2] != -1) {
        return dp[depth][d1][d2];
    }  

    int target = arr[depth];
    int dis_d1 = abs(target-d1);
    int dis_d2 = abs(target-d2);

    return dp[depth][d1][d2] = min(dis_d1 + dfs(depth+1, target, d2), dis_d2 + dfs(depth+1, d1, target));
}

int main() {
 
    cin >> n;
    cin >> d1_start >> d2_start;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        cin >> arr[i];
    }
    
    for(int i=0; i<21; i++) {
        for(int j=0; j<21; j++) {
            for(int k=0; k<21; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    dfs(0, d1_start, d2_start);

    cout << dp[0][d1_start][d2_start];
    
}