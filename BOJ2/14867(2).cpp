    #include <iostream>
    #include <string>
    #include <map>
    #include <algorithm>
    #define MAX 1000000000
    using namespace std;

    int ans = 1000000000;
    int a_max, b_max, a_target, b_target;

    map<pair<int, int>, int> dp;
   
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


       //  cout << cmd << ": " << now_a << " " << now_b << "\n\n";
        if(now_a == a_target && now_b == b_target) {
            ans = min(ans, depth);
            return;
        }

        if(dp[{now_a,now_b}] == 0) {
            dp[{now_a,now_b}] = depth;
            dfs(depth + 1, "a_fill", now_a, now_b);
            dfs(depth + 1, "a_empty", now_a, now_b);
            dfs(depth + 1, "b_fill", now_a, now_b);
            dfs(depth + 1, "b_empty", now_a, now_b);
            dfs(depth + 1, "move_a_b", now_a, now_b);
            dfs(depth + 1, "move_b_a", now_a, now_b);
        } else if (dp[{now_a,now_b}] > depth) {
            dp[{now_a,now_b}] = depth;
            dfs(depth + 1, "a_fill", now_a, now_b);
            dfs(depth + 1, "a_empty", now_a, now_b);
            dfs(depth + 1, "b_fill", now_a, now_b);
            dfs(depth + 1, "b_empty", now_a, now_b);
            dfs(depth + 1, "move_a_b", now_a, now_b);
            dfs(depth + 1, "move_b_a", now_a, now_b);
        }
    }


    int main() {

        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        cin >> a_max >> b_max >> a_target >> b_target; 

        dfs(0, "first", 0, 0);

        if(ans == MAX) cout << -1;
        else cout << ans;
    }