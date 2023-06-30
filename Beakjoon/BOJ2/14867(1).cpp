    #include <iostream>
    #include <string>
    #include <algorithm>
    #define MAX 1000000000
    using namespace std;

    int ans = MAX;
    int a_max, b_max, a_target, b_target;
    int dp[1001][1001];

    void dfs(int depth, string cmd, int now_a, int now_b) {
        if(now_a > a_max || now_a < 0 || now_b > b_max || now_b < 0) return;

        // cout << "depth " << depth << ": " << now_a << " " << now_b << "\n";

        if(cmd == "a_fill") {
            now_a = a_max;
        } else if(cmd == "b_fill") {
            now_b = b_max;
        } else if(cmd == "a_empty") {
            now_a = 0;
        } else if(cmd == "b_empty") {
            now_b = 0;
        } else if(cmd == "move_a_b") {
            if(now_a <= b_max - now_b) {
                now_b += now_a;
                now_a = 0;
            } else {
                now_a -= (b_max - now_b);
                now_b = b_max;
            }
        } else if(cmd == "move_b_a") {
            if(now_b <= a_max - now_a) {
                now_a += now_b;
                now_b = 0;
            } else {
                now_b -= (a_max - now_a);
                now_a = a_max;
            }
        }

        // cout << cmd << ": " << now_a << " " << now_b << "\n\n";
        if(now_a == a_target && now_b == b_target) {
            ans = min(ans, depth);
            return;
        }

        if(dp[now_a][now_b] > depth) {
            dp[now_a][now_b] = depth;
            dfs(depth + 1, "a_fill", now_a, now_b);
            dfs(depth + 1, "a_empty", now_a, now_b);
            dfs(depth + 1, "b_fill", now_a, now_b);
            dfs(depth + 1, "b_empty", now_a, now_b);
            dfs(depth + 1, "move_a_b", now_a, now_b);
            dfs(depth + 1, "move_b_a", now_a, now_b);
        }
        
    }


    int main() {


        for(int i=0; i<1001; i++) {
            for(int j=0; j<1001; j++) {
                dp[i][j] = MAX;
            }
        }

        cin >> a_max >> b_max >> a_target >> b_target;   
        dfs(0, "first", 0, 0);

        if(ans == MAX) cout << -1;
        else cout << ans;
    }