#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, w;
pair<int, int>arr[1001];

int dp[1001][1001];

int dfs(int depth, int c1_x, int c1_y, int c2_x, int c2_y, int x_last, int y_last) {

    cout << x_last << " " << y_last << "\n";
    if(depth == w + 1) {
        return 0;
    }

    if(dp[x_last][y_last] != -1) {
        return dp[x_last][y_last];
    }

    int target_x = arr[depth].first;
    int target_y = arr[depth].second;

    int c1_dix = abs(c1_x - target_x) + abs(c1_y - target_y);
    int c2_dix = abs(c2_x - target_x) + abs(c2_y - target_y);

    int if_c1 = dfs(depth + 1, target_x, target_y, c2_x, c2_y, depth, y_last) + c1_dix;
    int if_c2 = dfs(depth + 1, c1_x, c1_y, target_x, target_y, x_last, depth) + c2_dix;
    
    return dp[x_last][y_last] = min(if_c1, if_c2);

}

int main() {
    cin >> n;
    cin >> w;

    for(int i=1; i<=w; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        arr[i].first = input1;
        arr[i].second = input2;
    }

    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dp[i][j] = -1;
        }
    }

    dfs(1, 1, 1, w, w, 0, 0);

    cout << dp[0][0];
}